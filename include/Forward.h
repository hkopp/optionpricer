#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"

//! This class implements Forwards
class Forward : public AbstractDerivative
{
    public:
        //! constructs a Forward with a strike price and expiry time
        Forward(double strikeK, double expiryT);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // FORWARD_H
