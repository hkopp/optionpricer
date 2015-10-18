#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EuropeanCallOption
#include "../include/DigitalCallOption.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

DigitalCallOption c (50.0, 10.0);

BOOST_AUTO_TEST_CASE(Getters)
{
	BOOST_CHECK(c.GetExpiry() == 10.0);
}

BOOST_AUTO_TEST_CASE(Trivial_Price)
//Some trivial price checks
{
	DigitalCallOption c1 (50.0, 0.0);
	BOOST_CHECK_CLOSE(c1.Payoff(10.0), 0.0, 0.00001);
	BOOST_CHECK_CLOSE(c1.Payoff(70.0), 1.0, 0.00001);
}
