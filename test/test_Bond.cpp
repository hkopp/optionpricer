#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BlackScholesFormulas
#include "../include/Bond.h"
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Bond_Getter)
//Just a basic test of the Getters
{
	Bond b (1,5);
	BOOST_CHECK(b.GetFacevalue() == 1);
	BOOST_CHECK(b.GetExpiry() == 5);
}
