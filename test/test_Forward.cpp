#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Forward
#include "Forward.h"
#include <boost/test/unit_test.hpp>

Forward f (50.0, 10.0);

BOOST_AUTO_TEST_CASE(Getters)
{
    BOOST_CHECK(f.GetExpiry() == 10.0);
    BOOST_CHECK(f.GetStrike() == 50.0);
}
