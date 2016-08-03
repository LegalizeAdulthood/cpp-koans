#include "iterator.h"
#include <iterator>

// In each test, replace XXX with syntax that passes the test.

BOOST_AUTO_TEST_CASE(beginning_of_an_array)
{
	int values[5]{ 1, 2, 3, 4, 5 };
	BOOST_REQUIRE_EQUAL(&values[xxx], std::begin(values));
}

BOOST_AUTO_TEST_CASE(ending_of_an_array)
{
	int values[5]{ 1, 2, 3, 4, 5 };
	BOOST_REQUIRE_EQUAL(&values[xxx], std::end(values));
}

BOOST_AUTO_TEST_CASE(type_of_array_begin_iterator)
{
	int values[5]{ 1, 2, 3, 4, 5 };
	BOOST_REQUIRE((std::is_same<XXX, decltype(std::begin(values))>::value));
	BOOST_REQUIRE((std::is_same<XXX, decltype(std::cbegin(values))>::value));
}

BOOST_AUTO_TEST_CASE(iterator_traits_of_array_iterators)
{
	int values[]{ 1, 2, 3, 4, 5 };
	auto start = std::begin(values);
	BOOST_REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::value_type>::value));
	BOOST_REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::difference_type>::value));
	BOOST_REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::pointer>::value));
	BOOST_REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::reference>::value));
	BOOST_REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::iterator_category>::value));
}
