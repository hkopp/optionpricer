#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double strike_, double expiry_)
:strike(strike_),expiry(expiry_)
{
}

double DigitalPutOption::Payoff(double currentspot) const
{
    return currentspot > strike ? 0 : 1;
}
double DigitalPutOption::GetExpiry() const
{
	return expiry;
}
double DigitalPutOption::GetStrike() const
{
	return strike;
}
