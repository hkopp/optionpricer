//In this file we test different Put-Call Parities.
//This does not belong to a single class, but rather tests multiple classes. 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PutCallParity
#include "BlackScholesFormulas.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

double accuracy = 3;

BOOST_AUTO_TEST_CASE(PC_EuropeanOptions)
{
	//EuropeanCall - EuropeanPut = Forward
	double callprice = BlackScholesFormulas::EuropeanCallPrice(0.03, 0.01, 50.0, 0.03, 50.0, 10.0);
	double putprice = BlackScholesFormulas::EuropeanPutPrice(0.03, 0.01, 50.0, 0.03, 50.0, 10.0);
	double forwardprice = BlackScholesFormulas::ForwardPrice(0.03, 0.01, 50.0, 0.03, 50.0, 10.0);
    BOOST_CHECK_CLOSE(callprice - putprice, forwardprice, accuracy);
}

BOOST_AUTO_TEST_CASE(PC_DigitalOptions)
{
	//DigitalCall - DigitalPut = Bond
	double callprice = BlackScholesFormulas::DigitalCallPrice(0.05, 0.01, 50.0, 0.03, 50.0, 10.0);
	double putprice = BlackScholesFormulas::DigitalPutPrice(0.05, 0.01, 50.0, 0.03, 50.0, 10.0);
	double bondprice = BlackScholesFormulas::BondPrice(0.05, 1.0, 10.0);
    BOOST_CHECK_CLOSE(callprice - putprice, bondprice, accuracy);
}
