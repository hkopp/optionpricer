#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Forward
#include "MonteCarlo.h"
#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

double accuracy = 3;

BOOST_AUTO_TEST_CASE(MC_EuropeanCallOption)
{
	EuropeanCallOption c (50.0, 10.0);
	double analyticprice = c.GetPrice(0.03, 0.01, 50.0, 0.03);
	double simulatedprice = MonteCarlo::SimulatePrice(c, 1000, 0.03, 0.01, 50.0, 0.03);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}

BOOST_AUTO_TEST_CASE(MC_EuropeanPutOption)
{
	EuropeanCallOption p (50.0, 10.0);
	double analyticprice = p.GetPrice(0.03, 0.01, 50.0, 0.03);
	double simulatedprice = MonteCarlo::SimulatePrice(p, 1000, 0.03, 0.01, 50.0, 0.03);
    BOOST_CHECK_CLOSE(analyticprice, simulatedprice, accuracy);
}
