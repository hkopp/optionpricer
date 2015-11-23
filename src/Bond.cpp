#include "Bond.h"
#include <cmath>

Bond::Bond(double facevalue_, double expiry_)
{
    this->facevalue = facevalue_;
    this->expiry = expiry_;
}

double Bond::Payoff() const
{
	return facevalue;
}

double Bond::GetExpiry() const
{
	return expiry;
}
double Bond::GetFacevalue() const
{
	return facevalue;
}
