#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MonteCarlo
#include "MonteCarlo.h"
#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "MersenneTwisterRNG.h"
#include "BlackScholesFormulas.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

double accuracy = 3;
MersenneTwisterRNG RNG (5);

BOOST_AUTO_TEST_CASE(MC_EuropeanCallOption)
{
	double analyticprice = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.03, 50.0, 10.0);
	EuropeanCallOption c (50.0, 10.0);
	double simulatedprice = MonteCarlo::SimulatePrice(c, 1000, 0.03, 0.01, 50.0, 0.03, RNG);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}

BOOST_AUTO_TEST_CASE(MC_EuropeanPutOption)
{
	double analyticprice = BlackScholesFormulas::EuropeanPutPrice(0.03, 0.01, 30.0, 0.03, 50.0, 10.0);
	EuropeanPutOption p (50.0, 10.0);
	double simulatedprice = MonteCarlo::SimulatePrice(p, 1000, 0.03, 0.01, 30.0, 0.03, RNG);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}

BOOST_AUTO_TEST_CASE(MC_DigitalCallOption)
{
	double analyticprice = BlackScholesFormulas::DigitalCallPrice(0.03, 0.01, 50.0, 0.03, 50.0, 10.0);
	DigitalCallOption c (50.0, 10.0);
	double simulatedprice = MonteCarlo::SimulatePrice(c, 1000, 0.03, 0.01, 50.0, 0.03, RNG);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}

BOOST_AUTO_TEST_CASE(MC_DigitalPutOption)
{
	double analyticprice = BlackScholesFormulas::DigitalPutPrice(0.03, 0.01, 40.0, 0.03, 50.0, 10.0);
	DigitalPutOption p (50.0, 10.0);
	double simulatedprice = MonteCarlo::SimulatePrice(p, 1000, 0.03, 0.01, 40.0, 0.03, RNG);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}
