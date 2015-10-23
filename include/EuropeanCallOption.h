#ifndef EUROPEANCALLOPTION_H
#define EUROPEANCALLOPTION_H

#include "AbstractDerivative.h"

//! This class implements European Call options.
class EuropeanCallOption : public AbstractDerivative
{
    public:
        //! constructs a European Call option with a strike price and expiry time
        EuropeanCallOption(double strikeK, double expiryT);
        //! returns the analytical price of the call option
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // EUROPEANCALLOPTION_H
