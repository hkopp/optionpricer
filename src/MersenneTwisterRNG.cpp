#include "MersenneTwisterRNG.h"
#include "Random.h" //MoroInverseCumulativeNormal
#include <random>

MersenneTwisterRNG::MersenneTwisterRNG(unsigned int seed)
:mt(seed),seed(seed)
{
}

void MersenneTwisterRNG::Reset()
{
	mt.seed(seed);
}

double MersenneTwisterRNG::GetGaussian()
{
	double uniform = double(mt())/mt.max();
	return Random::MoroInverseCumulativeNormal(uniform);
}
