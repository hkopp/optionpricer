#ifndef RANDOM_H
#define RANDOM_H

//! A class for stochastic functions
/*!
 * This class provides often-needed stochastic functions
 */
class Random
{
    public:
		//! The inverse cumulative normal function due to Moro
        static double MoroInverseCumulativeNormal(double);

        //! The cumulative standard normal function
        static double CumulativeNormal(double);

        //! The probability density function of the standard normal distribution
        static double PDFNormal(double);
    protected:
    private:
};

#endif // RANDOM_H
