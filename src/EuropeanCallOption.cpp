#include "EuropeanCallOption.h"

EuropeanCallOption::EuropeanCallOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double EuropeanCallOption::Payoff(double currentspot) const
{
	return currentspot-strikeK > 0.0 ? currentspot-strikeK : 0;
}

double EuropeanCallOption::GetExpiry() const
{
	return expiryT;
}
