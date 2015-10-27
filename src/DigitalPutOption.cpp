#include "DigitalPutOption.h"
#include "Random.h"
#include <cmath>

DigitalPutOption::DigitalPutOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double DigitalPutOption::GetPrice(double rater, double dividend, double spot, double sigma) const
{
	double d2=(std::log(spot/strikeK)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	return std::exp(-rater*expiryT)*Random::CumulativeNormal(-d2); //pricing in interest rates
}

double DigitalPutOption::Payoff(double currentspot) const
{
    return currentspot > strikeK ? 0 : 1;
}
double DigitalPutOption::GetExpiry() const
{
	return expiryT;
}
