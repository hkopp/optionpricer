#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"


class Forward : public AbstractDerivative
{
    public:
        Forward();
        Forward(float T, float r, float d, float K, float S, float sigma);
        float GetPrice();
        float Payoff(float currentspot);
    protected:
    private:
};

#endif // FORWARD_H
