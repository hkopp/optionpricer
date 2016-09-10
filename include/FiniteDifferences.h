#ifndef FINITEDIFFERENCES_H
#define FINITEDIFFERENCES_H

#include "AbstractDerivative.h"

//! A class for computing the Greeks of Derivatives with finite differences. We are using central differences and the analytical prices of derivatives.
template <class Derivative_Type>
class FiniteDifferences
{
    public:
        //! computes the Delta of a derivative
        /*!
         * The inputs are as follows:
         * \param Derivative The Derivative
         * \param expiryT The expiry time
         * \param rater The continuous compounding rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The Volatility sigma
         * \param epsilon The size of the approximation interval
         * \return the Delta of the derivative computed with a central difference
         */
        static double Delta(Derivative_Type Derivative, double rater, double dividend, double spot, double sigma, double epsilon);
        //TODO: gamma, vega, theta, rho
    protected:
    private:
};

#endif // FINITEDIFFERENCES_H
