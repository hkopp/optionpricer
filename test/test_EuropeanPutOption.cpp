#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EuropeanCallOption
#include "../include/EuropeanPutOption.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>

EuropeanPutOption p (50.0, 10.0);

BOOST_AUTO_TEST_CASE(Getters)
{
	BOOST_CHECK(p.GetExpiry() == 10.0);
	BOOST_CHECK(p.GetStrike() == 50.0);
}

BOOST_AUTO_TEST_CASE(Trivial_Price)
//Some trivial payoff checks
{
	EuropeanPutOption p1 (50.0, 0.0);
	BOOST_CHECK_CLOSE(p1.Payoff(10.0), 40.0, 0.00001);
	BOOST_CHECK_CLOSE(p1.Payoff(70.0), 0.0, 0.00001);
}
