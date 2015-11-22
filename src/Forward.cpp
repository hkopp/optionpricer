#include "Forward.h"
#include <cmath>

Forward::Forward(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double Forward::Payoff(double currentspot) const
{
    return currentspot; //at expiry, a forward pays the price of the underlying
}
double Forward::GetExpiry() const
{
	return expiryT;
}
