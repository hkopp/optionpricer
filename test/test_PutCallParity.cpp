//In this file we test different Put-Call Parities.
//This does not belong to a single class, but rather tests multiple classes. 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PutCallParity
#include "MonteCarlo.h"
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
	EuropeanCallOption c (50.0, 10.0);
	EuropeanPutOption p (50.0, 10.0);
	Forward f (50.0, 10.0);
	double callprice = c.GetPrice(0.03, 0.01, 50.0, 0.03);
	double putprice = p.GetPrice(0.03, 0.01, 50.0, 0.03);
	double forwardprice = f.GetPrice(0.03, 0.01, 50.0, 0.03);
    BOOST_CHECK_CLOSE(callprice - putprice, forwardprice, accuracy);
}

BOOST_AUTO_TEST_CASE(PC_DigitalOptions)
{
	//DigitalCall - DigitalPut = Bond
	DigitalCallOption c (50.0, 10.0);
	DigitalPutOption p (50.0, 10.0);
	Bond b (1.0, 10.0);
	double callprice = c.GetPrice(0.05, 0.01, 50.0, 0.03);
	double putprice = p.GetPrice(0.05, 0.01, 50.0, 0.03);
	double bondprice = b.GetPrice(0.05);
    BOOST_CHECK_CLOSE(callprice - putprice, bondprice, accuracy);
}
