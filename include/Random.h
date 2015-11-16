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

        //! The cumulative normal function
        static double CumulativeNormal(double);

        //! Returns a normally distributed random variable
        static double GetGaussian(); //TODO: this should be deleted and an AbstractRNG used, where this is invoked now
    protected:
    private:
};

#endif // RANDOM_H
