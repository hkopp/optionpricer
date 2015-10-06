#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"


class Forward : public AbstractDerivative
{
    public:
        Forward();
        Forward(double strikeK, double expiryT);
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // FORWARD_H
