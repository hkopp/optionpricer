#ifndef EUROPEANCALLOPTION_H
#define EUROPEANCALLOPTION_H

#include "AbstractDerivative.h"

//! This class implements European Call options.
class EuropeanCallOption : public AbstractDerivative
{
    public:
        //! constructs a European Call option with a strike price and expiry time
        EuropeanCallOption(double strike_, double expiry_);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
        double GetStrike() const;
    protected:
    private:
        double strike;
        double expiry;
};

#endif // EUROPEANCALLOPTION_H
