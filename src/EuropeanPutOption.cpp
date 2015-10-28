#include "EuropeanPutOption.h"
#include "Random.h"
#include <cmath>

EuropeanPutOption::EuropeanPutOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double EuropeanPutOption::GetPrice(double rater, double dividend, double spot, double sigma) const
{
	//TODO: assert sigma != 0 && expiryT !=0
	double d1=(std::log(spot/strikeK)+(rater-dividend+1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	double d2=d1-sigma*std::sqrt(expiryT);
//	double d2=(std::log(spot/strikeK)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	return spot*std::exp(-dividend*expiryT)*Random::CumulativeNormal(-d1) - strikeK*std::exp(-rater*expiryT)*Random::CumulativeNormal(-d2);

}

double EuropeanPutOption::Payoff(double currentspot) const
{
	return currentspot > strikeK ? 0 : currentspot-strikeK;
}

double EuropeanPutOption::GetExpiry() const
{
	return expiryT;
}
