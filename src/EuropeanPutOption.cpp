#include "EuropeanPutOption.h"
#include "Random.h"
#include <cmath>

EuropeanPutOption::EuropeanPutOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double EuropeanPutOption::Payoff(double currentspot) const
{
	return currentspot > strikeK ? 0 : currentspot-strikeK;
}

double EuropeanPutOption::GetExpiry() const
{
	return expiryT;
}
