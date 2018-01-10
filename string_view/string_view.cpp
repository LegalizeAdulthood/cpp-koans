#include "string_view.h"

using namespace std::string_literals;

BOOST_AUTO_TEST_CASE(std_string_view_variants)
{
    BOOST_REQUIRE((std::is_same_v<XXX, std::basic_string_view<char>>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::wstring_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u16string_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u32string_view>));
}

BOOST_AUTO_TEST_CASE(std_string_view_related_types)
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

BOOST_AUTO_TEST_CASE(std_string_view_constructors)
{
    constexpr std::string_view s;
    BOOST_REQUIRE_EQUAL(xxx, s.empty());

    constexpr std::string_view s2{"Hello, world!", 5};
    BOOST_REQUIRE_EQUAL(xxx, s2.length());
    BOOST_REQUIRE_EQUAL(xxx, s2);

    /* constexpr */ std::string_view s3{"Hello, world!"};
    BOOST_REQUIRE_EQUAL(xxx, s3.length());
}

BOOST_AUTO_TEST_CASE(std_string_view_accessors)
{
    constexpr std::string_view s{"Hello, world!", 13};
    BOOST_REQUIRE_EQUAL(xxx, s[0]);
    BOOST_REQUIRE_EQUAL(xxx, s.at(0));
    BOOST_REQUIRE_THROW(s.at(100), XXX);
    BOOST_REQUIRE_EQUAL(xxx, s.front());
    BOOST_REQUIRE_EQUAL(xxx, s.back());
    BOOST_REQUIRE((std::is_same_v<decltype(s.data()), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, *s.data());
}

BOOST_AUTO_TEST_CASE(std_string_view_capacity)
{
    constexpr std::string_view s{"Hello, world!", 13};
    BOOST_REQUIRE_EQUAL(xxx, s.size());
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_EQUAL(xxx, s.empty());
    BOOST_REQUIRE_GE(s.max_size(), static_cast<std::string_view::size_type>(xxx));
}

BOOST_AUTO_TEST_CASE(std_string_view_modifiers)
{
    std::string_view s{"Hello, world!", 13};
    s.remove_prefix(xxx);
    BOOST_REQUIRE_EQUAL("world!"s, s);
    s.remove_suffix(xxx);
    BOOST_REQUIRE_EQUAL("world"s, s);
}

BOOST_AUTO_TEST_CASE(std_string_view_swap)
{
    std::string_view s{"Hello, world!", 13};
    std::string_view s2{"Woof!", 5};
    s.swap(s2);
    BOOST_REQUIRE_EQUAL("xxx"s, s);
    BOOST_REQUIRE_EQUAL("xxx"s, s2);
}

BOOST_AUTO_TEST_CASE(std_string_view_iterators)
{
    std::string_view s{"Hello, world!"};

    BOOST_REQUIRE((std::is_same_v<decltype(s.begin()), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s.cbegin()), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, *s.begin());
    BOOST_REQUIRE_EQUAL(xxx, *(s.end() - 1));
    BOOST_REQUIRE_EQUAL(xxx, *s.rbegin());
    BOOST_REQUIRE_EQUAL(xxx, *(s.rend() - 1));
}
