#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H

//! A virtual class for financial derivatives
/*!
 * This is the base class which all derivatives should inherit.
 */
class AbstractDerivative
{
    public:
        virtual ~AbstractDerivative() = default;
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
        //! The Strike of the derivative
        /*!
         * \return the strike price of the derivative
         */
        virtual double GetStrike() const = 0;
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
