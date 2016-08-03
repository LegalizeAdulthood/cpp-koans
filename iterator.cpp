#include "iterator.h"
#include <iterator>

// In each test, replace XXX with syntax that passes the test.

BOOST_AUTO_TEST_CASE(beginning_of_an_array)
{
	int values[5]{ 1, 2, 3, 4, 5 };
	BOOST_REQUIRE_EQUAL(&values[xxx], std::begin(values));
}
