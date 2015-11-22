#include "DigitalCallOption.h"
#include "Random.h"
#include <cmath>

DigitalCallOption::DigitalCallOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double DigitalCallOption::Payoff(double currentspot) const
{
    return currentspot > strikeK ? 1 : 0;
}
double DigitalCallOption::GetExpiry() const
{
	return expiryT;
}
