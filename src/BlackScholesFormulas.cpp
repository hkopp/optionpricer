#include "BlackScholesFormulas.h"
#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"
#include "Forward.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "Bond.h"
#include "Random.h"
#include <cmath>

double BlackScholesFormulas::GetPrice(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall)
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/europeancall.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeancall.GetExpiry())/(sigma*std::sqrt(europeancall.GetExpiry()));
	double d2=d1-sigma*std::sqrt(europeancall.GetExpiry());
	//	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiry));
	return spot*std::exp(-dividend*europeancall.GetExpiry())*Random::CumulativeNormal(d1) - europeancall.GetStrike()*std::exp(-rater*europeancall.GetExpiry())*Random::CumulativeNormal(d2);
}

double BlackScholesFormulas::GetPrice(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput)
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/europeanput.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeanput.GetExpiry())/(sigma*std::sqrt(europeanput.GetExpiry()));
	double d2=d1-sigma*std::sqrt(europeanput.GetExpiry());
	//	double d2=(std::log(spot/strike)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiry));
	return spot*std::exp(-dividend*europeanput.GetExpiry())*Random::CumulativeNormal(-d1) - europeanput.GetStrike()*std::exp(-rater*europeanput.GetExpiry())*Random::CumulativeNormal(-d2);
}

double BlackScholesFormulas::GetPrice(double rater, double dividend, double spot, double sigma, const Forward& forward)
{
    return std::exp(-rater*forward.GetExpiry())*(std::exp((rater-dividend)*forward.GetExpiry())*spot - forward.GetStrike());
}

double BlackScholesFormulas::GetPrice(double rater, double dividend, double spot, double sigma, const DigitalCallOption& digitalcall)
{
	double d2=(std::log(spot/digitalcall.GetStrike())+(rater-dividend-1/2*std::pow(sigma,2))*digitalcall.GetExpiry())/(sigma*std::sqrt(digitalcall.GetExpiry()));
	return std::exp(-rater*digitalcall.GetExpiry())*Random::CumulativeNormal(d2);
}

double BlackScholesFormulas::GetPrice(double rater, double dividend, double spot, double sigma, const DigitalPutOption& digitalput)
{
	double d2=(std::log(spot/digitalput.GetStrike())+(rater-dividend-1/2*std::pow(sigma,2))*digitalput.GetExpiry())/(sigma*std::sqrt(digitalput.GetExpiry()));
	return std::exp(-rater*digitalput.GetExpiry())*Random::CumulativeNormal(-d2); //pricing in interest rates
}

double BlackScholesFormulas::GetPrice(double rater, const Bond& bond)
{
	return bond.GetFacevalue()*std::exp(-rater*bond.GetExpiry());
}

double GetDelta(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall)
{
	double d1=(std::log(spot/europeancall.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeancall.GetExpiry())/(sigma*std::sqrt(europeancall.GetExpiry()));
	return Random::CumulativeNormal(d1);
}

double GetDelta(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput)
{
	double d1=(std::log(spot/europeanput.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeanput.GetExpiry())/(sigma*std::sqrt(europeanput.GetExpiry()));
	return Random::CumulativeNormal(d1) - 1;
}

double GetVega(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall)
{
	double d1=(std::log(spot/europeancall.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeancall.GetExpiry())/(sigma*std::sqrt(europeancall.GetExpiry()));
	return spot*Random::PDFNormal(d1)*std::sqrt(europeancall.GetExpiry());
}

double GetVega(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput)
{
	double d1=(std::log(spot/europeanput.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeanput.GetExpiry())/(sigma*std::sqrt(europeanput.GetExpiry()));
	return spot*Random::PDFNormal(d1)*std::sqrt(europeanput.GetExpiry());
}

double GetTheta(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall)
{
	double d1=(std::log(spot/europeancall.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeancall.GetExpiry())/(sigma*std::sqrt(europeancall.GetExpiry()));
	double d2=d1-sigma*std::sqrt(europeancall.GetExpiry());
	double T = europeancall.GetExpiry();
	double K = europeancall.GetStrike();
	return -spot*Random::PDFNormal(d1)*sigma/(2*std::sqrt(T)) - rater*K*std::exp(-rater*K)*Random::CumulativeNormal(d2);
}

double GetTheta(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput)
{
	double d1=(std::log(spot/europeanput.GetStrike())+(rater-dividend+1/2*std::pow(sigma,2))*europeanput.GetExpiry())/(sigma*std::sqrt(europeanput.GetExpiry()));
	double d2=d1-sigma*std::sqrt(europeanput.GetExpiry());
	double T = europeanput.GetExpiry();
	double K = europeanput.GetStrike();
	return -spot*Random::PDFNormal(d1)*sigma/(2*std::sqrt(T)) + rater*K*std::exp(-rater*K)*Random::CumulativeNormal(-d2);

}

double GetRho(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall)
{
	double d2=(std::log(spot/europeancall.GetStrike())+(rater-dividend-1/2*std::pow(sigma,2))*europeancall.GetExpiry())/(sigma*std::sqrt(europeancall.GetExpiry()));
	return europeancall.GetStrike()*europeancall.GetExpiry()*std::exp(-rater*europeancall.GetExpiry())*Random::CumulativeNormal(d2);
}

double GetRho(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput)
{
	double d2=(std::log(spot/europeanput.GetStrike())+(rater-dividend-1/2*std::pow(sigma,2))*europeanput.GetExpiry())/(sigma*std::sqrt(europeanput.GetExpiry()));
	return -europeanput.GetStrike()*europeanput.GetExpiry()*std::exp(-rater*europeanput.GetExpiry())*Random::CumulativeNormal(-d2);
}
