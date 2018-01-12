#include "iterator.h"
#include <iterator>

// In each test, replace XXX with syntax that passes the test.

TEST_CASE("array iterators")
{
	int values[5]{ 1, 2, 3, 4, 5 };

	REQUIRE(&values[xxx] == std::begin(values));
	REQUIRE(&values[xxx] == std::end(values));
	REQUIRE((std::is_same<XXX, decltype(std::begin(values))>::value));
	REQUIRE((std::is_same<XXX, decltype(std::cbegin(values))>::value));
}

TEST_CASE("iterator traits of array iterators")
{
	int values[]{ 1, 2, 3, 4, 5 };
	auto start = std::begin(values);

	REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::value_type>::value));
	REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::difference_type>::value));
	REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::pointer>::value));
	REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::reference>::value));
	REQUIRE((std::is_same<XXX, std::iterator_traits<decltype(start)>::iterator_category>::value));
}
