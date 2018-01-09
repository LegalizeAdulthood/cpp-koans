#include "strings.h"

BOOST_AUTO_TEST_CASE(std_string_variants)
{
    BOOST_REQUIRE((std::is_same_v<std::string, std::basic_string<XXX>>));
    BOOST_REQUIRE((std::is_same_v<std::wstring, std::basic_string<XXX>>));
    BOOST_REQUIRE((std::is_same_v<std::u16string, std::basic_string<XXX>>));
    BOOST_REQUIRE((std::is_same_v<std::u32string, std::basic_string<XXX>>));
}

BOOST_AUTO_TEST_CASE(std_string_related_types)
{
    BOOST_REQUIRE((std::is_same_v<std::string::traits_type, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::value_type, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::reference, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::const_reference, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::reverse_iterator, std::reverse_iterator<XXX>>));
    BOOST_REQUIRE((std::is_same_v<std::string::const_reverse_iterator, std::reverse_iterator<XXX>>));
}

BOOST_AUTO_TEST_CASE(std_string_constructors)
{
    std::string const s1;
    BOOST_REQUIRE_EQUAL(xxx, s1.length());

    std::string const s2{5, 'E'};
    BOOST_REQUIRE_EQUAL(xxx, s2.length());

    std::string const s3{s2};
    BOOST_REQUIRE_EQUAL(xxx, s3.length());

    std::string const s4{s2, 1};
    BOOST_REQUIRE_EQUAL(xxx, s4.length());

    std::string const hw{"Hello, world!"};
    std::string const s5{hw, 1, 4};
    BOOST_REQUIRE_EQUAL(xxx, s5);

    std::string const s6{"Hello, world!"};
    BOOST_REQUIRE_EQUAL(xxx, s6.length());

    std::string const s7{"Hello, world!", 5};
    BOOST_REQUIRE_EQUAL(xxx, s7);

    std::string const s8{s7.begin(), s7.begin() + 1};
    BOOST_REQUIRE_EQUAL(xxx, s8);

    std::string const s9{'H', 'e', 'l', 'l', 'o'};
    BOOST_REQUIRE_EQUAL(xxx, s9);
}

BOOST_AUTO_TEST_CASE(std_string_literals)
{
    using namespace std::literals::string_literals;
    auto s1{"Hello, world!"s};
    auto s2{L"Hello, world!"s};
    auto s3{u"Hello, world!"s};
    auto s4{U"Hello, world!"s};
    BOOST_REQUIRE((std::is_same_v<decltype(s1), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s2), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s3), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s4), XXX>));
}

BOOST_AUTO_TEST_CASE(std_string_accessors)
{
    std::string s{"Hello, world!"};

    BOOST_REQUIRE_EQUAL(xxx, s[0]);
    BOOST_REQUIRE_EQUAL('w', s.at(xxx));
    BOOST_REQUIRE_THROW(s.at(1000), XXX);
    BOOST_REQUIRE_EQUAL(xxx, s.front());
    BOOST_REQUIRE_EQUAL(xxx, s.back());
    BOOST_REQUIRE((std::is_same_v<decltype(s.data()), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s.c_str()), XXX>));
}

BOOST_AUTO_TEST_CASE(string_iterators)
{
}

BOOST_AUTO_TEST_CASE(std_string_allocators)
{
    BOOST_REQUIRE((std::is_same_v<std::string::allocator_type, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::size_type, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::difference_type, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::pointer, XXX>));
    BOOST_REQUIRE((std::is_same_v<std::string::const_pointer, XXX>));
}
