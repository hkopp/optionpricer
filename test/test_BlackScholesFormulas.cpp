#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BlackScholesFormulas
#include "../include/BlackScholesFormulas.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	EuropeanCallOption call1 (20,10);
	EuropeanCallOption call2 (30,10);
	EuropeanCallOption call3 (40,10);
	EuropeanCallOption call4 (50,10);
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call1) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call2));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call2) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call3));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call3) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call4));
}

BOOST_AUTO_TEST_CASE(DigitalCall_Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	DigitalCallOption dcall1 (20.0, 10.0);
	DigitalCallOption dcall2 (30.0, 10.0);
	DigitalCallOption dcall3 (40.0, 10.0);
	DigitalCallOption dcall4 (50.0, 10.0);
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall1) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall2));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall2) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall3));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall3) >= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall4));
}

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Volatility)
//The price of a call option should be monotonously increasing with volatility
{
	EuropeanCallOption call (40.0, 10.0);
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.4, call) <= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.5, call));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.6, call) <= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, call));
}

BOOST_AUTO_TEST_CASE(DigitalCall_Monotony_Volatility)
//The price of a call option should be monotonously increasing with volatility
{
	DigitalCallOption dcall (40.0, 10.0);
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.4, dcall) <= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.5, dcall));
	BOOST_CHECK(BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.6, dcall) <= BlackScholesFormulas::GetPrice(0.04, 0.02, 10.0, 0.7, dcall));
}

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Expiration)
//If d=0 the price of a call should be increasing with the expiration date T
{
	EuropeanCallOption call (30.0, 10.0);
	double ecallprice1 = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.0, call);
	double ecallprice2 = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.0, call);
	double ecallprice3 = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.0, call);
	BOOST_CHECK(ecallprice1 <= ecallprice2);
	BOOST_CHECK(ecallprice2 <= ecallprice3);
}

BOOST_AUTO_TEST_CASE(European_Rational_Bounds)
//The price of a call option should be between the spot and spot-Ke^rT
{
	EuropeanCallOption call (30.0, 10.0);
	double callprice1 = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.0, call);
	BOOST_CHECK(50.0-30.0*std::exp(0.03*10.0) <= callprice1);
	BOOST_CHECK(callprice1 <= 50);

	double callprice2 = BlackScholesFormulas::GetPrice(0.05, 0.01, 100.0, 0.04, call);
	BOOST_CHECK(100.0-30.0*std::exp(0.05*10.0) <= callprice2);
	BOOST_CHECK(callprice2 <= 100);
}


BOOST_AUTO_TEST_CASE(Digital_Rational_Bounds)
//The price of a digital call option should be between 0 and 1
{
	DigitalCallOption dcall (30.0, 10.0);
	double callprice1 = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.04, dcall);
	BOOST_CHECK(0 <= callprice1);
	BOOST_CHECK(callprice1 <= 1);

	double callprice2 = BlackScholesFormulas::GetPrice(0.05, 0.01, 100.0, 0.04, dcall);
	BOOST_CHECK(0 <= callprice2);
	BOOST_CHECK(callprice2 <= 1);
}


BOOST_AUTO_TEST_CASE(European_Trivial_Deltas)
//Test the correct output of some simple deltas
{
	EuropeanCallOption call (50.0, 0.0);
	BOOST_CHECK_CLOSE(BlackScholesFormulas::GetDelta(0.2, 0.1, 55, 0.3, call), 1.0, 0.00001);
	BOOST_CHECK_CLOSE(BlackScholesFormulas::GetDelta(0.2, 0.1, 45, 0.3, call), 0.0, 0.00001);

	EuropeanPutOption put (50.0, 0.0);
	BOOST_CHECK_CLOSE(BlackScholesFormulas::GetDelta(0.2, 0.1, 55, 0.3, put), 0.0, 0.00001);
	BOOST_CHECK_CLOSE(BlackScholesFormulas::GetDelta(0.2, 0.1, 45, 0.3, put), -1.0, 0.00001);
}

BOOST_AUTO_TEST_CASE(European_Trivial_Gammas)
//Test the correct output of some simple gammas.
{
	EuropeanPutOption put (50.0, 20.0);
	BOOST_CHECK_CLOSE(BlackScholesFormulas::GetDelta(0.0, 0.0, 50, 0.3, put), -0.5, 0.00001);
}
