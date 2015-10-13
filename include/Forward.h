#ifndef FORWARD_H
#define FORWARD_H

#include "AbstractDerivative.h"

//! This class implements Forwards
class Forward : public AbstractDerivative
{
    public:
        //! constructs a Forward with a strike price and expiry time
        Forward(double strikeK, double expiryT);
        //! returns the analytical price of a forward
        /*!
         * The inputs are the parameters needed in the Black-Scholes model, namely
         * \param rater The continuous computing rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The Volatility sigma
         * \return the analytical price of the forward
         */
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // FORWARD_H
