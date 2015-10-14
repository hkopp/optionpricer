#include "Bond.h"
#include <cmath>

Bond::Bond(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double Bond::GetPrice(double rater, double dividend, double spot, double sigma) const
{
	return strikeK*std::exp(-rater*expiryT);
}

double Bond::Payoff(double currentspot) const
{
	return strikeK;
}

double Bond::GetExpiry() const
{
	return expiryT;
}
