#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H

//! A virtual class for financial derivatives
/*!
 * This is the base class which all derivatives should inherit.
 */
class AbstractDerivative
{
    public:
        virtual ~AbstractDerivative();

        //! returns the analytical Black-Scholes price of the asset
        /*!
         * The inputs are the parameters needed in the Black-Scholes model, namely
         * \param rater The continuous computing rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The Volatility sigma
         * \return the analytical price of the derivative
         */
        virtual double GetPrice(double rater, double dividend, double spot, double sigma) const = 0; //pure virtual function which has to be implemented

        //! The Payoff of the derivative
        /*!
         * \param currentspot The current spot price of the underlying
         * \return the payoff of the derivative
         */
        virtual double Payoff(double currentspot) const = 0;
        //! The Expiration of the derivative
        /*!
         * \return the expiration time of the derivative
         */
        virtual double GetExpiry() const = 0;
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
