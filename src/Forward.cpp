#include "Forward.h"
#include <cmath>

Forward::Forward()
{
    //ctor
}

Forward::Forward(double strikeK)
{
    this->strikeK = strikeK;
}

double Forward::GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const
{
    return std::exp(-rater*expiryT)*(std::exp((rater-dividend)*expiryT)*spot - strikeK);
}

double Forward::Payoff(double currentspot) const
{
    return currentspot; //at expiry, a forward pays the price of the underlying
}
