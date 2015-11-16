#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "AbstractDerivative.h"
#include "AbstractRNG.h"

//! A class for Monte-Carlo simulation of option prices
class MonteCarlo
{
    public:
        MonteCarlo();

        //! simulates the price of a derivative
        /*!
         * The inputs are the parameters needed in the Black-Scholes model, namely
         * \param Derivative The Derivative to price
         * \param numberRuns the number of runs on which to average
         * \param expiryT The expiry time
         * \param rater The continuous computing rate
         * \param dividend The dividend rate
         * \param spot The spot price of the underlying
         * \param sigma The Volatility sigma
         * \return the price of the derivative computed with Monte Carlo method
         */
        static double SimulatePrice(const AbstractDerivative& Derivative, unsigned int numberRuns, double rater, double dividend, double spot, double sigma, AbstractRNG& RNG);
    protected:
    private:
};

#endif // MONTECARLO_H
