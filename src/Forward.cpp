#include "Forward.h"
#include <cmath>

Forward::Forward()
{
    //ctor
}

Forward::Forward(float strikeK)
{
    this->strikeK = strikeK;
}

float Forward::GetPrice(float expiryT, float rater, float dividend, float spot, float sigma)
{
    return std::exp(-rater*expiryT)*(std::exp((rater-dividend)*expiryT)*spot - strikeK);
}

float Forward::Payoff(float currentspot)
{
    return currentspot; //at expiry, a forward pays the price of the underlying
}
