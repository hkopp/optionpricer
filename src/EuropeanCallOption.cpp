#include "EuropeanCallOption.h"
#include "Random.h"
#include <cmath>

EuropeanCallOption::EuropeanCallOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double EuropeanCallOption::GetPrice(double rater, double dividend, double spot, double sigma) const
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/strikeK)+(rater-dividend+1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	double d2=d1-sigma*std::sqrt(expiryT);
//	double d2=(std::log(spot/strikeK)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	return spot*std::exp(-dividend*expiryT)*Random::CumulativeNormal(d1) - strikeK*std::exp(-rater*expiryT)*Random::CumulativeNormal(d2);
    
}

double EuropeanCallOption::Payoff(double currentspot) const
{
	return currentspot-strikeK > 0.0 ? currentspot-strikeK : 0;
}

double EuropeanCallOption::GetExpiry() const
{
	return expiryT;
}
