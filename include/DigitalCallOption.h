#ifndef DigitalCallOption_H
#define DigitalCallOption_H

#include "AbstractDerivative.h"

//! This class implements Digital Cash-or-Nothing Call options.
class DigitalCallOption : public AbstractDerivative
{
    public:
		DigitalCallOption(double strike_, double expiry_);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
        double GetStrike() const;
    protected:
    private:
        double strike;
        double expiry;
};

#endif // DigitalCallOption_H
