#include "DigitalCallOption.h"
#include "Random.h"
#include <cmath>

DigitalCallOption::DigitalCallOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double DigitalCallOption::GetPrice(double rater, double dividend, double spot, double sigma) const
{
	double d2=(std::log(spot/strikeK)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	return std::exp(-rater*expiryT)*Random::CumulativeNormal(d2);
}

double DigitalCallOption::Payoff(double currentspot) const
{
    return currentspot > strikeK ? 1 : 0; //at expiry, a forward pays the price of the underlying
}
double DigitalCallOption::GetExpiry() const
{
	return expiryT;
}
