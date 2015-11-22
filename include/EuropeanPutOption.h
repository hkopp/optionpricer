#ifndef EUROPEANPUTOPTION_H
#define EUROPEANPUTOPTION_H

#include "AbstractDerivative.h"

//! This class implements European Put options.
class EuropeanPutOption : public AbstractDerivative
{
    public:
        //! constructs a European Put option with a strike price and expiry time
        EuropeanPutOption(double strikeK, double expiryT);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // EUROPEANPUTOPTION_H
