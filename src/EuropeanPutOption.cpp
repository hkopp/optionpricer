#include "EuropeanPutOption.h"

EuropeanPutOption::EuropeanPutOption(double strike_, double expiry_)
:strike(strike_),expiry(expiry_)
{
}

double EuropeanPutOption::Payoff(double currentspot) const
{
	return currentspot > strike ? 0 : strike-currentspot;
}

double EuropeanPutOption::GetExpiry() const
{
	return expiry;
}
double EuropeanPutOption::GetStrike() const
{
	return strike;
}
