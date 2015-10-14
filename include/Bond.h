#ifndef BOND_H
#define BOND_H

#include "AbstractDerivative.h"

class Bond : public AbstractDerivative
{
    public:
		Bond(double strikeK, double expiryT);
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // BOND_H
