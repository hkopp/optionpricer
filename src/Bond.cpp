#include "Bond.h"
#include <cmath>

Bond::Bond(double strikeK, double expiryT)
{
    this->strikeK = strikeK;
    this->expiryT = expiryT;
}

double Bond::GetPrice(double rater) const
{
	return strikeK*std::exp(-rater*expiryT);
}

double Bond::Payoff() const
{
	return strikeK;
}

double Bond::GetExpiry() const
{
	return expiryT;
}
