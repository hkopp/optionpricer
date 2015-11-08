#ifndef MERSENNETWISTERRNG_H
#define MERSENNETWISTERRNG_H

#include <random>
#include "AbstractRNG.h"

//! A class for random number generation according to the Mersenne Twister
class MersenneTwisterRNG : public AbstractRNG
{
    public:
		MersenneTwisterRNG(unsigned int seed = 0);
		~MersenneTwisterRNG();
		void Reset();
		double GetGaussian();
	protected:
	private:
		std::mt19937 mt;
		unsigned int seed;
};

#endif // MERSENNETWISTERRNG_H
