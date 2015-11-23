#ifndef EUROPEANPUTOPTION_H
#define EUROPEANPUTOPTION_H

#include "AbstractDerivative.h"

//! This class implements European Put options.
class EuropeanPutOption : public AbstractDerivative
{
    public:
        //! constructs a European Put option with a strike price and expiry time
        EuropeanPutOption(double strike_, double expiry_);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
        double GetStrike() const;
    protected:
    private:
        double strike;
        double expiry;
};

#endif // EUROPEANPUTOPTION_H
