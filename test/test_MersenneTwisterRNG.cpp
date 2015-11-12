#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MersenneTwisterRNG
#include "MersenneTwisterRNG.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Deterministic)
{
	MersenneTwisterRNG m1 (5);
	MersenneTwisterRNG m2 (5);
    BOOST_CHECK(m1.GetGaussian() == m2.GetGaussian());
}

BOOST_AUTO_TEST_CASE(Reset)
{
	MersenneTwisterRNG m1 (1);
	double random1 = m1.GetGaussian();
	m1.Reset();
	double random2 = m1.GetGaussian();
    BOOST_CHECK(random1 == random2);
}

//TODO: check mean and variance
