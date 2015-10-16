#ifndef DigitalCallOption_H
#define DigitalCallOption_H

#include "AbstractDerivative.h"

//! This class implements Digital Cash-or-Nothing Call options.
class DigitalCallOption : public AbstractDerivative
{
    public:
		DigitalCallOption(double strikeK, double expiryT);
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // DigitalCallOption_H
