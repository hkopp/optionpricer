#include "Bond.h"
#include <cmath>

Bond::Bond(double facevalue, double expiryT)
{
    this->facevalue = facevalue;
    this->expiryT = expiryT;
}

double Bond::GetPrice(double rater) const
{
	return facevalue*std::exp(-rater*expiryT);
}

double Bond::Payoff() const
{
	return facevalue;
}

double Bond::GetExpiry() const
{
	return expiryT;
}
