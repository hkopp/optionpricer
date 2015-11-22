#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DigitalCallOption
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

BOOST_AUTO_TEST_CASE(Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	DigitalCallOption c1 (30.0, 10.0);
	DigitalCallOption c2 (40.0, 10.0);
	DigitalCallOption c3 (50.0, 10.0);
	DigitalCallOption c4 (60.0, 10.0);
	BOOST_CHECK(c1.Payoff(50.0) >= c2.Payoff(50.0));
	BOOST_CHECK(c2.Payoff(50.0) >= c3.Payoff(50.0));
	BOOST_CHECK(c3.Payoff(50.0) >= c4.Payoff(50.0));
}

BOOST_AUTO_TEST_CASE(Rational_Bounds)
//The price of a digital call option should be between 0 and 1
{
	DigitalCallOption c1 (30.0, 10.0);
	BOOST_CHECK(0 <= c1.GetPrice(0.03, 0.01, 50.0, 0.04));
	BOOST_CHECK(c1.GetPrice(0.03, 0.01, 50.0, 0.04 <= 1));

	BOOST_CHECK(0 <= c1.GetPrice(0.05, 0.01, 100.0, 0.04));
	BOOST_CHECK(c1.GetPrice(0.05, 0.01, 100.0, 0.04) <= 1);
}
