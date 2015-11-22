#include "DigitalPutOption.h"
#include "Random.h"
#include <cmath>

DigitalPutOption::DigitalPutOption(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double DigitalPutOption::Payoff(double currentspot) const
{
    return currentspot > strikeK ? 0 : 1;
}
double DigitalPutOption::GetExpiry() const
{
	return expiryT;
}
