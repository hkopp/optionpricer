//In this file we test different Put-Call Parities.
//This does not belong to a single class, but rather tests multiple classes. 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PutCallParity
#include "BlackScholesFormulas.h"
#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"
#include "Forward.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "Bond.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

double accuracy = 3;

BOOST_AUTO_TEST_CASE(PC_EuropeanOptions)
{
	//EuropeanCall - EuropeanPut = Forward
	EuropeanCallOption call (50.0, 10.0);
	EuropeanPutOption put (50.0, 10.0);
	Forward forward (50.0, 10.0);
	double callprice = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.03, call);
	double putprice = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.03, put);
	double forwardprice = BlackScholesFormulas::GetPrice(0.03, 0.01, 50.0, 0.03, forward);
    BOOST_CHECK_CLOSE(callprice - putprice, forwardprice, accuracy);
}

BOOST_AUTO_TEST_CASE(PC_DigitalOptions)
{
	//DigitalCall - DigitalPut = Bond
	DigitalCallOption call (50.0, 10.0);
	DigitalPutOption put (50.0, 10.0);
	Bond bond (1.0, 10.0);
	double callprice = BlackScholesFormulas::GetPrice(0.05, 0.01, 50.0, 0.03, call);
	double putprice = BlackScholesFormulas::GetPrice(0.05, 0.01, 50.0, 0.03, put);
	double bondprice = BlackScholesFormulas::GetPrice(0.05, bond);
    BOOST_CHECK_CLOSE(callprice - putprice, bondprice, accuracy);
}
