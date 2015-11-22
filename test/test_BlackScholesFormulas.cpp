#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BlackScholesFormulas
#include "../include/BlackScholesFormulas.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	BOOST_CHECK(BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 20.0, 10.0) >= BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 30.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 30.0, 10.0) >= BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0) >= BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 50.0, 10.0));
}

BOOST_AUTO_TEST_CASE(DigitalCall_Monotony_Strike)
//The price of a call option should be monotonously decreasing with strike
{
	BOOST_CHECK(BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 20.0, 10.0) >= BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 30.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 30.0, 10.0) >= BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0) >= BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 50.0, 10.0));
	//EuropeanCallPrice(double rater, double dividend, double spot, double sigma, double strike, double expiry)
}

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Volatility)
//The price of a call option should be monotonously increasing with volatility
{
	BOOST_CHECK(BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.4, 40.0, 10.0) <= BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.5, 40.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.6, 40.0, 10.0) <= BlackScholesFormulas::EuropeanCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0));
}

BOOST_AUTO_TEST_CASE(DigitalCall_Monotony_Volatility)
//The price of a call option should be monotonously increasing with volatility
{
	BOOST_CHECK(BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.4, 40.0, 10.0) <= BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.5, 40.0, 10.0));
	BOOST_CHECK(BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.6, 40.0, 10.0) <= BlackScholesFormulas::DigitalCallPrice(0.04, 0.02, 10.0, 0.7, 40.0, 10.0));
}

BOOST_AUTO_TEST_CASE(EuropeanCall_Monotony_Expiration)
//If d=0 the price of a call should be increasing with the expiration date T
{
	double ecallprice1 = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.0, 30.0, 10.0);
	double ecallprice2 = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.0, 30.0, 20.0);
	double ecallprice3 = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.0, 30.0, 30.0);
	BOOST_CHECK(ecallprice1 <= ecallprice2);
	BOOST_CHECK(ecallprice2 <= ecallprice3);
}

BOOST_AUTO_TEST_CASE(European_Rational_Bounds)
//The price of a call option should be between the spot and spot-Ke^rT
{
	double callprice1 = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.0, 30.0, 10.0);
	BOOST_CHECK(50.0-30.0*std::exp(0.03*10.0) <= callprice1);
	BOOST_CHECK(callprice1 <= 50);

	double callprice2 = BlackScholesFormulas::EuropeanCallPrice(0.05, 0.01, 100.0, 0.04, 30.0, 10.0);
	BOOST_CHECK(100.0-30.0*std::exp(0.05*10.0) <= callprice2);
	BOOST_CHECK(callprice2 <= 100);
}


BOOST_AUTO_TEST_CASE(Digital_Rational_Bounds)
//The price of a digital call option should be between 0 and 1
{
	double callprice1 = BlackScholesFormulas::DigitalCallPrice(0.03, 0.01, 50.0, 0.04, 30.0, 10.0);
	BOOST_CHECK(0 <= callprice1);
	BOOST_CHECK(callprice1 <= 1);

	double callprice2 = BlackScholesFormulas::DigitalCallPrice(0.05, 0.01, 100.0, 0.04, 30.0, 10.0);
	BOOST_CHECK(0 <= callprice2);
	BOOST_CHECK(callprice2 <= 1);
}
