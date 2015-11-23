#include "EuropeanPutOption.h"

EuropeanPutOption::EuropeanPutOption(double strike_, double expiry_)
{
    this->strike = strike_;
    this->expiry = expiry_;
}

double EuropeanPutOption::Payoff(double currentspot) const
{
	return currentspot > strike ? 0 : currentspot-strike;
}

double EuropeanPutOption::GetExpiry() const
{
	return expiry;
}
double EuropeanPutOption::GetStrike() const
{
	return strike;
}
