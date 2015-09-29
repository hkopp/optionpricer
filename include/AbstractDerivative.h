#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H

//! A virtual class for financial derivatives
/*!
 * This is the base class which all derivatives should inherit.
 */
class AbstractDerivative
{
    public:
        AbstractDerivative();
        virtual double GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const = 0; //pure virtual function which has to be implemented
        virtual double Payoff(double currentspot) = 0; //!< The Payoff given the current spot.
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
