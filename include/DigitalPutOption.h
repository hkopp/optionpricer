#ifndef DigitalPutOption_H
#define DigitalPutOption_H

#include "AbstractDerivative.h"

//! This class implements Digital Cash-or-Nothing Put options.
class DigitalPutOption : public AbstractDerivative
{
    public:
		DigitalPutOption(double strike_, double expiry_);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
        double GetStrike() const;
    protected:
    private:
        double strike;
        double expiry;
};

#endif // DigitalPutOption_H
