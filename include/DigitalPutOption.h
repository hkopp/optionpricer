#ifndef DigitalPutOption_H
#define DigitalPutOption_H

#include "AbstractDerivative.h"

//! This class implements Digital Cash-or-Nothing Put options.
class DigitalPutOption : public AbstractDerivative
{
    public:
		DigitalPutOption(double strikeK, double expiryT);
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // DigitalPutOption_H
