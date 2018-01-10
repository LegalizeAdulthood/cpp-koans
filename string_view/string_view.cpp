#include "string_view.h"

using namespace std::string_literals;
using namespace std::string_view_literals;

BOOST_AUTO_TEST_CASE(std_string_view_variants)
{
    BOOST_REQUIRE((std::is_same_v<XXX, std::basic_string_view<char>>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::wstring_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u16string_view>));
    BOOST_REQUIRE((std::is_same_v<XXX, std::u32string_view>));
}

BOOST_AUTO_TEST_CASE(std_string_view_literals)
{
    BOOST_REQUIRE((std::is_same_v<XXX, decltype("foo"sv)>));
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
    BOOST_REQUIRE_EQUAL("world!"sv, s);
    s.remove_suffix(xxx);
    BOOST_REQUIRE_EQUAL("world"sv, s);
}

BOOST_AUTO_TEST_CASE(std_string_view_swap)
{
    std::string_view s{"Hello, world!", 13};
    std::string_view s2{"Woof!", 5};
    s.swap(s2);
    BOOST_REQUIRE_EQUAL("xxx"sv, s);
    BOOST_REQUIRE_EQUAL("xxx"sv, s2);
}

BOOST_AUTO_TEST_CASE(std_string_view_copy)
{
    constexpr std::string_view s{"Hello, world!", 13};
    char dest[5];
    s.copy(dest, sizeof(dest));
    BOOST_REQUIRE_EQUAL("xxx"s, std::string(std::begin(dest), std::end(dest)));
    s.copy(dest, sizeof(dest), xxx);
    BOOST_REQUIRE_EQUAL("world"s, std::string(std::begin(dest), std::end(dest)));
}

BOOST_AUTO_TEST_CASE(std_string_view_substr)
{
    constexpr std::string_view s{"Hello, world!", 13};
    constexpr auto s2{s.substr()};
    BOOST_REQUIRE((std::is_same_v<decltype(s2), XXX>));
    BOOST_REQUIRE_EQUAL("xxx"sv, s2);
    auto s3{s.substr(xxx)};
    BOOST_REQUIRE_EQUAL("world!"sv, s3);
    auto s4{s.substr(xxx, xxx)};
    BOOST_REQUIRE_EQUAL("world"sv, s4);
    constexpr auto s5{s.substr(3, std::string_view::npos)};
    BOOST_REQUIRE_EQUAL("xxx"sv, s5);
}

BOOST_AUTO_TEST_CASE(std_string_comparison_operators)
{
    constexpr std::string_view alpha{"Alpha", 5};
    BOOST_REQUIRE("xxx"sv < alpha);
    BOOST_REQUIRE("xxx"sv > alpha);
    BOOST_REQUIRE("xxx"sv <= alpha);
    BOOST_REQUIRE("xxx"sv >= alpha);
    // change both xxx's to the same thing to make this true
    BOOST_REQUIRE("xxx"sv <= alpha && "xxx"sv >= alpha);
    BOOST_REQUIRE("xxx"sv == alpha);
    BOOST_REQUIRE(static_cast<std::string_view>(xxx) != alpha);
}

BOOST_AUTO_TEST_CASE(std_string_view_compare)
{
    std::string_view s1{"Alphabetical", 12};
    std::string_view s2{"Alphanumerical", 14};
    auto res1 = s1.compare(s2);
    BOOST_REQUIRE((std::is_same_v<decltype(res1), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res1);

    BOOST_REQUIRE_EQUAL(0, s1.compare(xxx, 5, s2));
    BOOST_REQUIRE_EQUAL(0, s1.compare(xxx, 3, s2, 11, 3));
    BOOST_REQUIRE_EQUAL(0, s1.compare("xxx"));
    BOOST_REQUIRE_EQUAL(0, s1.compare(xxx, 4, "ical"));
    BOOST_REQUIRE_EQUAL(0, s1.compare(xxx, 4, "Canonical", 5));
}

BOOST_AUTO_TEST_CASE(std_string_view_find)
{
    constexpr std::string_view s{"Have a fun day at the zoo.", 26};
    auto res = s.find("a"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    char ch{xxx};
    BOOST_REQUIRE_EQUAL(4, s.find(ch));
    BOOST_REQUIRE_EQUAL(6, s.find(ch, xxx));
    BOOST_REQUIRE_EQUAL(xxx, s.find("!"sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find("!"s));
    BOOST_REQUIRE_EQUAL(14, s.find(" a"sv, xxx));
    BOOST_REQUIRE_EQUAL(xxx, s.find(" a"));
    BOOST_REQUIRE_EQUAL(14, s.find(" a", xxx));
    BOOST_REQUIRE_EQUAL(4, s.find(" a", xxx, 1));

    BOOST_REQUIRE_EQUAL(xxx, ""sv.find(ch));
    BOOST_REQUIRE_EQUAL(xxx, "foo"sv.find(ch, 10));
    BOOST_REQUIRE_EQUAL(xxx, "foo"sv.find("f"sv, 10));
    BOOST_REQUIRE_EQUAL(xxx, "foo"sv.find("fo", 10));
}

BOOST_AUTO_TEST_CASE(std_string_view_rfind)
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.rfind("oo"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo"sv, 6));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo"));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo", 6));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo", 6, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind('y'));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind('y', 14));
}

BOOST_AUTO_TEST_CASE(std_string_view_find_first_of)
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_first_of("EGF"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF"sv, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF", 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF", 1, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o', 3));
    
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of(""sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of(""));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("ABC"sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("ABC"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('A'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o"sv, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_view_find_first_not_of)
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_first_not_of("ABCDEFG"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("oab"sv, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF", 3));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF", 3, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('o', 1));

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("Fobar GglyEes"sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("Fobar GglyEes"));
    BOOST_REQUIRE_EQUAL(xxx, s.substr(1, 1).find_first_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o"sv, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_view_find_last_of)
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_last_of("EGF"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF"sv, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF", 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF", 1, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o', 3));

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of(""sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of(""));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("ABC"sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("ABC"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('A'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o"sv, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_view_find_last_not_of)
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_last_not_of("ABCDEFG"sv);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("oab"sv, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF", 3));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF", 3, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('o', 1));

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("Fobar GglyEes"sv));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("Fobar GglyEes"));
    BOOST_REQUIRE_EQUAL(xxx, s.substr(1, 1).find_last_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o"sv, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('o', 100));
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
