#ifndef BLACKSCHOLESFORMULAS_H
#define BLACKSCHOLESFORMULAS_H

//! A class for analytic functions in the Black-Scholes model
/*!
 * This class provides functions for computing the price of derivatives in the Black-Scholes model
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
        static double EuropeanCallPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry);

        //! The price of a european put option
        static double EuropeanPutPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry);

        //! The price of a forward
        static double ForwardPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry);

        static double DigitalCallPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry);
        static double DigitalPutPrice(double rater, double dividend, double spot, double sigma,  double strike, double expiry);
		//! Computes the price of a bond.
        static double BondPrice(double rater, double facevalue, double expiry);
    protected:
    private:
};

#endif // BLACKSCHOLESFORMULAS_H
