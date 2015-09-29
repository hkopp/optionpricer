#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"


class Forward : public AbstractDerivative
{
    public:
        Forward();
        Forward(double strikeK);
        double GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot);
    protected:
    private:
        double strikeK;
};

#endif // FORWARD_H
