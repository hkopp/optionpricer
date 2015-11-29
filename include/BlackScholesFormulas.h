#ifndef BLACKSCHOLESFORMULAS_H
#define BLACKSCHOLESFORMULAS_H

#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"
#include "Forward.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "Bond.h"

//! A class for analytic functions in the Black-Scholes model
/*!
 * This class provides functions for computing the price and other attributes of derivatives in the Black-Scholes model
 */
class BlackScholesFormulas
{
    public:
		//! The price of a european call option
    	/*!
    	 * The inputs are the parameters needed in the Black-Scholes model, namely
    	 * \param rater The continuous computing rate
    	 * \param dividend The dividend rate
    	 * \param spot The spot price of the underlying
    	 * \param sigma The Volatility sigma
    	 * \return the analytical price of the derivative
    	 */
		static double GetPrice(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall);

		//! The price of a european put option
		static double GetPrice(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput);

        //! The price of a forward
        static double GetPrice(double rater, double dividend, double spot, double sigma, const Forward& forward);

        //! Computes the price of a digital call option.
        static double GetPrice(double rater, double dividend, double spot, double sigma, const DigitalCallOption& digitalcall);

        //! Computes the price of a digital put option.
        static double GetPrice(double rater, double dividend, double spot, double sigma, const DigitalPutOption& digitalput);

		//! Computes the price of a bond.
        static double GetPrice(double rater, const Bond& bond);

		//! The delta of a european call option
		static double GetDelta(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall);

		//! The delta of a european put option
		static double GetDelta(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput);

		//! The vega of a european call option
		static double GetVega(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall);

		//! The vega of a european put option
		static double GetVega(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput);

		//! The theta of a european call option
		static double GetTheta(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall);

		//! The theta of a european put option
		static double GetTheta(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput);

		//! The rho of a european call option
		static double GetRho(double rater, double dividend, double spot, double sigma, const EuropeanCallOption& europeancall);

		//! The rho of a european put option
		static double GetRho(double rater, double dividend, double spot, double sigma, const EuropeanPutOption& europeanput);
    protected:
    private:
};

#endif // BLACKSCHOLESFORMULAS_H
