#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double strike_, double expiry_)
:strike(strike_),expiry(expiry_)
{
}

double DigitalCallOption::Payoff(double currentspot) const
{
    return currentspot > strike ? 1 : 0;
}
double DigitalCallOption::GetExpiry() const
{
	return expiry;
}
double DigitalCallOption::GetStrike() const
{
	return strike;
}
