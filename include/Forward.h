#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"

//! This class implements Forwards
class Forward : public AbstractDerivative
{
    public:
        //! constructs a Forward with a strike price and expiry time
        Forward(double strike_, double expiry_);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
        double GetStrike() const;
    protected:
    private:
        double strike;
        double expiry;
};

#endif // FORWARD_H
