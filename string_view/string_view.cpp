#include "string_view.h"

BOOST_AUTO_TEST_CASE(string_view_variants)
{
    BOOST_REQUIRE((std::is_same_v<XXX, std::basic_string_view<char>>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::wstring_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u16string_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u32string_view>));
}

BOOST_AUTO_TEST_CASE(string_view_related_types)
{
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::traits_type>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::value_type>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::pointer>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::const_pointer>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::reference>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::const_reference>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::size_type>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::string_view::difference_type>));
}

BOOST_AUTO_TEST_CASE(string_view_constructors)
{
    constexpr std::string_view s;
    BOOST_REQUIRE_EQUAL(xxx, s.empty());

    constexpr std::string_view s2{"Hello, world!", 5};
    BOOST_REQUIRE_EQUAL(xxx, s.length());
}
