#ifndef EUROPEANPUTOPTION_H
#define EUROPEANPUTOPTION_H

#include "AbstractDerivative.h"

class EuropeanPutOption : public AbstractDerivative
{
    public:
        EuropeanPutOption(double strikeK, double expiryT);
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // EUROPEANPUTOPTION_H
