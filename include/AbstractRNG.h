#ifndef ABSTRACTRNG_H
#define ABSTRACTRNG_H

//! A virtual class for random number generators
/*!
 * This is the base class which all random number generators should inherit.
 * I have to implement my own RNGs because the random number generator used within C++ is not defined in the standard.
 * Thus compiling on different platforms, even with the same seed can lead to different random numbers.
 * Also this provides the possibility to extend random number generation by using antithetic variates or some other fancy mechanism.
 */
class AbstractRNG
{
    public:
        virtual ~AbstractRNG() = default;

        //! resets the random number generator to the initial state
        virtual void Reset() = 0;

        //! Returns a normally distributed random variable
        virtual double GetGaussian() = 0;
    protected:
    private:
};

#endif // ABSTRACTRNG_H
