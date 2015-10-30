#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EuropeanCallOption
#include "../include/EuropeanCallOption.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

EuropeanCallOption c (50.0, 10.0);

BOOST_AUTO_TEST_CASE(Getters)
{
	BOOST_CHECK(c.GetExpiry() == 10.0);
}

BOOST_AUTO_TEST_CASE(Trivial_Price)
//Some trivial price checks
{
	EuropeanCallOption c1 (50.0, 0.0);
	BOOST_CHECK_CLOSE(c1.Payoff(10.0), 0.0, 0.00001);
	BOOST_CHECK_CLOSE(c1.Payoff(70.0), 20.0, 0.00001);
}

BOOST_AUTO_TEST_CASE(Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	EuropeanCallOption c1 (30.0, 10.0);
	EuropeanCallOption c2 (40.0, 10.0);
	EuropeanCallOption c3 (50.0, 10.0);
	EuropeanCallOption c4 (60.0, 10.0);
	BOOST_CHECK(c1.Payoff(50.0) >= c2.Payoff(50.0));
	BOOST_CHECK(c2.Payoff(50.0) >= c3.Payoff(50.0));
	BOOST_CHECK(c3.Payoff(50.0) >= c4.Payoff(50.0));
}
