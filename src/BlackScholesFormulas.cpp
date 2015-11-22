#include "BlackScholesFormulas.h"
#include "Random.h"
#include <cmath>

double BlackScholesFormulas::EuropeanCallPrice(double rater, double dividend, double spot, double sigma, double strike, double expiry)
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/strike)+(rater-dividend+1/2*std::pow(sigma,2))*expiry)/(sigma*std::sqrt(expiry));
	double d2=d1-sigma*std::sqrt(expiry);
	//	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiry));
	return spot*std::exp(-dividend*expiry)*Random::CumulativeNormal(d1) - strike*std::exp(-rater*expiry)*Random::CumulativeNormal(d2);
}

double BlackScholesFormulas::EuropeanPutPrice(double rater, double dividend, double spot, double sigma, double strike, double expiry)
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/strike)+(rater-dividend+1/2*std::pow(sigma,2))*expiry)/(sigma*std::sqrt(expiry));
	double d2=d1-sigma*std::sqrt(expiry);
	//	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiry));
	return spot*std::exp(-dividend*expiry)*Random::CumulativeNormal(-d1) - strike*std::exp(-rater*expiry)*Random::CumulativeNormal(-d2);
}


double BlackScholesFormulas::ForwardPrice(double rater, double dividend, double spot, double sigma, double strike, double expiry)
{
    return std::exp(-rater*expiry)*(std::exp((rater-dividend)*expiry)*spot - strike);
}

double BlackScholesFormulas::DigitalCallPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry)
{
	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiry)/(sigma*std::sqrt(expiry));
	return std::exp(-rater*expiry)*Random::CumulativeNormal(d2);
}

double BlackScholesFormulas::DigitalPutPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry)
{
	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiry)/(sigma*std::sqrt(expiry));
	return std::exp(-rater*expiry)*Random::CumulativeNormal(-d2); //pricing in interest rates
}

double BlackScholesFormulas::BondPrice(double rater, double facevalue, double expiry)
{
	return facevalue*std::exp(-rater*expiry);
}
