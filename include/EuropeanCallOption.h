#ifndef EUROPEANCALLOPTION_H
#define EUROPEANCALLOPTION_H

#include "AbstractDerivative.h"

//! This class implements European Call options.
class EuropeanCallOption : public AbstractDerivative
{
    public:
        //EuropeanCallOption();

        //! constructs a European Call option with a strike price
        EuropeanCallOption(double strikeK);
        double GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot);
    protected:
    private:
        double strikeK;
};

#endif // EUROPEANCALLOPTION_H
