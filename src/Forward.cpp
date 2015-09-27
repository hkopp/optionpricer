#include "Forward.h"
#include <cmath>

Forward::Forward()
{
    //ctor
}

Forward::Forward(float nT, float nr, float nd, float nK, float nS, float nsigma)
{
    T = nT;
    r = nr;
    d = nd;
    K = nK;
    S = nS;
    sigma = nsigma;
}

float Forward::GetPrice()
{
    return std::exp(-r*T)*(std::exp((r-d)*T)*S - K);
}

float Forward::Payoff(float currentspot)
{
    return currentspot; //at expiry, a forward pays the price of the underlying
}
