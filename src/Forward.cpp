#include "Forward.h"
#include <cmath>

Forward::Forward(double strike_, double expiry_)
{
    this->strike = strike_;
    this->expiry = expiry_;
}

double Forward::Payoff(double currentspot) const
{
    return currentspot; //at expiry, a forward pays the price of the underlying
}
double Forward::GetExpiry() const
{
	return expiry;
}
double Forward::GetStrike() const
{
	return strike;
}
