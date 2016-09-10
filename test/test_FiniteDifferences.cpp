#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FiniteDifferences
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>
#include "../include/FiniteDifferences.h"
#include "../include/EuropeanCallOption.h"
#include "../include/EuropeanPutOption.h"

BOOST_AUTO_TEST_CASE(FD_European_Trivial_Deltas)
//Test the correct output of some simple deltas
{
	EuropeanCallOption call (50.0, 0.0);
	BOOST_CHECK_CLOSE(FiniteDifferences<EuropeanCallOption>::Delta(call, 0.2, 0.1, 55.0, 0.3, 0.0001), 1.0, 0.00001);
	BOOST_CHECK_CLOSE(FiniteDifferences<EuropeanCallOption>::Delta(call, 0.2, 0.1, 45.0, 0.3, 0.0001), 0.0, 0.00001);

	EuropeanPutOption put (50.0, 0.0);
	BOOST_CHECK_CLOSE(FiniteDifferences<EuropeanPutOption>::Delta(put, 0.2, 0.1, 55.0, 0.3, 0.0001), 0.0, 0.00001);
	BOOST_CHECK_CLOSE(FiniteDifferences<EuropeanPutOption>::Delta(put, 0.2, 0.1, 45.0, 0.3, 0.0001), -1.0, 0.00001);
}
