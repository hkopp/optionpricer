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
        /*!
         * The inputs are the parameters needed in the Black-Scholes model, namely
         * \param rater The continuous computing rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The Volatility sigma
         * \return the analytical price of the call
         */
        double GetPrice(double rater, double dividend, double spot, double sigma) const;
        double Payoff(double currentspot) const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // EUROPEANCALLOPTION_H
