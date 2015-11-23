#include "EuropeanCallOption.h"

EuropeanCallOption::EuropeanCallOption(double strike_, double expiry_)
:strike(strike_),expiry(expiry_)
{
}

double EuropeanCallOption::Payoff(double currentspot) const
{
	return currentspot-strike > 0.0 ? currentspot-strike : 0;
}

double EuropeanCallOption::GetExpiry() const
{
	return expiry;
}
double EuropeanCallOption::GetStrike() const
{
	return strike;
}
