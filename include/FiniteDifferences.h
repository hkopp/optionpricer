#ifndef FINITEDIFFERENCES_H
#define FINITEDIFFERENCES_H

#include "AbstractDerivative.h"
#include "BlackScholesFormulas.h"

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
         * \param sigma The volatility sigma
         * \param epsilon The size of the approximation interval
         * \return the Delta of the derivative computed with a central difference
         */
        static double Delta(Derivative_Type Derivative, double rater, double dividend, double spot, double sigma, double epsilon)
        {
        	double price_left = BlackScholesFormulas::GetPrice(rater, dividend, spot-epsilon, sigma, Derivative);
        	double price_right= BlackScholesFormulas::GetPrice(rater, dividend, spot+epsilon, sigma, Derivative);
        	return (price_right-price_left)/(2*epsilon);
        }
        //! computes the Vega of a derivative
        /*!
         * The inputs are as follows:
         * \param Derivative The Derivative
         * \param expiryT The expiry time
         * \param rater The continuous compounding rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The volatility sigma
         * \param epsilon The size of the approximation interval
         * \return the Vega of the derivative computed with a central difference
         */
        static double Vega(Derivative_Type Derivative, double rater, double dividend, double spot, double sigma, double epsilon)
        {
            double price_left = BlackScholesFormulas::GetPrice(rater, dividend, spot, sigma-epsilon, Derivative);
            double price_right= BlackScholesFormulas::GetPrice(rater, dividend, spot, sigma+epsilon, Derivative);
            return (price_right-price_left)/(2*epsilon);
        }

        //TODO: gamma, theta, rho
    protected:
    private:
};

#endif // FINITEDIFFERENCES_H
