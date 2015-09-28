#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"


class Forward : public AbstractDerivative
{
    public:
        Forward();
        Forward(float strikeK);
        float GetPrice(float expiryT, float rater, float dividend, float spot, float sigma);
        float Payoff(float currentspot);
    protected:
    private:
        float strikeK;
};

#endif // FORWARD_H
