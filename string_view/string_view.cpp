#include "string_view.h"

using namespace std::string_literals;
using namespace std::string_view_literals;

TEST_CASE("std::string view variants")
{
    REQUIRE((std::is_same_v<XXX, std::basic_string_view<char>>));
    REQUIRE((std::is_same_v<XXX, std::wstring_view>));
    REQUIRE((std::is_same_v<XXX, std::u16string_view>));
    REQUIRE((std::is_same_v<XXX, std::u32string_view>));
}

TEST_CASE("std::string_view literals")
{
    REQUIRE((std::is_same_v<XXX, decltype("foo"sv)>));
}

TEST_CASE("std::string_view related types")
{
    REQUIRE((std::is_same_v<XXX, std::string_view::traits_type>));
    REQUIRE((std::is_same_v<XXX, std::string_view::value_type>));
    REQUIRE((std::is_same_v<XXX, std::string_view::pointer>));
    REQUIRE((std::is_same_v<XXX, std::string_view::const_pointer>));
    REQUIRE((std::is_same_v<XXX, std::string_view::reference>));
    REQUIRE((std::is_same_v<XXX, std::string_view::const_reference>));
    REQUIRE((std::is_same_v<XXX, std::string_view::size_type>));
    REQUIRE((std::is_same_v<XXX, std::string_view::difference_type>));
}

TEST_CASE("std::string_view constructors")
{
    constexpr std::string_view s;
    REQUIRE(xxx == s.empty());

    constexpr std::string_view s2{"Hello, world!", 5};
    REQUIRE(xxx == s2.length());
    REQUIRE(xxx == s2);

    /* constexpr */ std::string_view s3{"Hello, world!"};
    REQUIRE(xxx == s3.length());
}

TEST_CASE("std::string_view accessors")
{
    constexpr std::string_view s{"Hello, world!", 13};
    REQUIRE(xxx == s[0]);
    REQUIRE(xxx == s.at(0));
    REQUIRE_THROWS_AS(s.at(100), XXX);
    REQUIRE(xxx == s.front());
    REQUIRE(xxx == s.back());
    REQUIRE((std::is_same_v<decltype(s.data()), XXX>));
    REQUIRE(xxx == *s.data());
}

TEST_CASE("std::string_view capacity")
{
    constexpr std::string_view s{"Hello, world!", 13};
    REQUIRE(xxx == s.size());
    REQUIRE(xxx == s.length());
    REQUIRE(xxx == s.empty());
    REQUIRE(s.max_size() >= static_cast<std::string_view::size_type>(xxx));
}

TEST_CASE("std::string_view modifiers")
{
    std::string_view s{"Hello, world!", 13};
    s.remove_prefix(xxx);
    REQUIRE("world!"sv == s);
    s.remove_suffix(xxx);
    REQUIRE("world"sv == s);
}

TEST_CASE("std::string_view swap")
{
    std::string_view s{"Hello, world!", 13};
    std::string_view s2{"Woof!", 5};
    s.swap(s2);
    REQUIRE("xxx"sv == s);
    REQUIRE("xxx"sv == s2);
}

TEST_CASE("std::string_view copy")
{
    constexpr std::string_view s{"Hello, world!", 13};
    char dest[5];
    s.copy(dest, sizeof(dest));
    REQUIRE("xxx"s == std::string(std::begin(dest), std::end(dest)));
    s.copy(dest, sizeof(dest), xxx);
    REQUIRE("world"s == std::string(std::begin(dest), std::end(dest)));
}

TEST_CASE("std::string_view substr")
{
    constexpr std::string_view s{"Hello, world!", 13};
    constexpr auto s2{s.substr()};
    REQUIRE((std::is_same_v<decltype(s2), XXX>));
    REQUIRE("xxx"sv == s2);
    auto s3{s.substr(xxx)};
    REQUIRE("world!"sv == s3);
    auto s4{s.substr(xxx, xxx)};
    REQUIRE("world"sv == s4);
    constexpr auto s5{s.substr(3, std::string_view::npos)};
    REQUIRE("xxx"sv == s5);
}

TEST_CASE("std_string_comparison_operators")
{
    constexpr std::string_view alpha{"Alpha", 5};
    REQUIRE("xxx"sv < alpha);
    REQUIRE("xxx"sv > alpha);
    REQUIRE("xxx"sv <= alpha);
    REQUIRE("xxx"sv >= alpha);
    REQUIRE("xxx"sv == alpha);
    REQUIRE("xxx"sv != alpha);
}

TEST_CASE("std::string_view compare")
{
    std::string_view s1{"Alphabetical", 12};
    std::string_view s2{"Alphanumerical", 14};
    auto res1 = s1.compare(s2);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == res1);

    REQUIRE(0 == s1.compare(xxx, 5, s2));
    REQUIRE(0 == s1.compare(xxx, 3, s2, 11, 3));
    REQUIRE(0 == s1.compare("xxx"));
    REQUIRE(0 == s1.compare(xxx, 4, "ical"));
    REQUIRE(0 == s1.compare(xxx, 4, "Canonical", 5));
}

TEST_CASE("std::string_view find")
{
    constexpr std::string_view s{"Have a fun day at the zoo.", 26};
    auto res = s.find("a"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    char ch{xxx};
    REQUIRE(4 == s.find(ch));
    REQUIRE(6 == s.find(ch, xxx));
    REQUIRE(xxx == s.find("!"sv));
    REQUIRE(xxx == s.find("!"s));
    REQUIRE(14 == s.find(" a"sv, xxx));
    REQUIRE(xxx == s.find(" a"));
    REQUIRE(14 == s.find(" a", xxx));
    REQUIRE(4 == s.find(" a", xxx, 1));

    REQUIRE(xxx == ""sv.find(ch));
    REQUIRE(xxx == "foo"sv.find(ch, 10));
    REQUIRE(xxx == "foo"sv.find("f"sv, 10));
    REQUIRE(xxx == "foo"sv.find("fo", 10));
}

TEST_CASE("std::string_view rfind")
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.rfind("oo"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.rfind("oo"sv, 6));
    REQUIRE(xxx == s.rfind("oo"));
    REQUIRE(xxx == s.rfind("oo", 6));
    REQUIRE(xxx == s.rfind("oo", 6, 1));
    REQUIRE(xxx == s.rfind('y'));
    REQUIRE(xxx == s.rfind('y', 14));
}

TEST_CASE("std::string_view find_first_of")
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_first_of("EGF"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_first_of("EGF"sv, 1));
    REQUIRE(xxx == s.find_first_of("EGF"));
    REQUIRE(xxx == s.find_first_of("EGF", 1));
    REQUIRE(xxx == s.find_first_of("EGF", 1, 1));
    REQUIRE(xxx == s.find_first_of('o'));
    REQUIRE(xxx == s.find_first_of('o', 3));
    
    REQUIRE(xxx == s.find_first_of(""sv));
    REQUIRE(xxx == s.find_first_of(""));
    REQUIRE(xxx == s.find_first_of("ABC"sv));
    REQUIRE(xxx == s.find_first_of("ABC"));
    REQUIRE(xxx == s.find_first_of('A'));
    REQUIRE(xxx == s.find_first_of("o"sv, 100));
    REQUIRE(xxx == s.find_first_of("o", 100));
    REQUIRE(xxx == s.find_first_of("o", 100, 1));
    REQUIRE(xxx == s.find_first_of('o', 100));
}

TEST_CASE("std::string_view find_first_not_of")
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_first_not_of("ABCDEFG"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_first_not_of("oab"sv, 1));
    REQUIRE(xxx == s.find_first_not_of("abF"));
    REQUIRE(xxx == s.find_first_not_of("abF", 3));
    REQUIRE(xxx == s.find_first_not_of("abF", 3, 1));
    REQUIRE(xxx == s.find_first_not_of('F'));
    REQUIRE(xxx == s.find_first_not_of('o', 1));

    REQUIRE(xxx == s.find_first_not_of("Fobar GglyEes"sv));
    REQUIRE(xxx == s.find_first_not_of("Fobar GglyEes"));
    REQUIRE(xxx == s.substr(1, 1).find_first_not_of('F'));
    REQUIRE(xxx == s.find_first_not_of("o"sv, 100));
    REQUIRE(xxx == s.find_first_not_of("o", 100));
    REQUIRE(xxx == s.find_first_not_of("o", 100, 1));
    REQUIRE(xxx == s.find_first_not_of('o', 100));
}

TEST_CASE("std::string_view find_last_of")
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_last_of("EGF"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_last_of("EGF"sv, 1));
    REQUIRE(xxx == s.find_last_of("EGF"));
    REQUIRE(xxx == s.find_last_of("EGF", 1));
    REQUIRE(xxx == s.find_last_of("EGF", 1, 1));
    REQUIRE(xxx == s.find_last_of('o'));
    REQUIRE(xxx == s.find_last_of('o', 3));

    REQUIRE(xxx == s.find_last_of(""sv));
    REQUIRE(xxx == s.find_last_of(""));
    REQUIRE(xxx == s.find_last_of("ABC"sv));
    REQUIRE(xxx == s.find_last_of("ABC"));
    REQUIRE(xxx == s.find_last_of('A'));
    REQUIRE(xxx == s.find_last_of("o"sv, 100));
    REQUIRE(xxx == s.find_last_of("o", 100));
    REQUIRE(xxx == s.find_last_of("o", 100, 1));
    REQUIRE(xxx == s.find_last_of('o', 100));
}

TEST_CASE("std::string_view find_last_not_of")
{
    constexpr std::string_view s{"Foobar Googly Eyes", 18};
    auto res = s.find_last_not_of("ABCDEFG"sv);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_last_not_of("oab"sv, 1));
    REQUIRE(xxx == s.find_last_not_of("abF"));
    REQUIRE(xxx == s.find_last_not_of("abF", 3));
    REQUIRE(xxx == s.find_last_not_of("abF", 3, 1));
    REQUIRE(xxx == s.find_last_not_of('F'));
    REQUIRE(xxx == s.find_last_not_of('o', 1));

    REQUIRE(xxx == s.find_last_not_of("Fobar GglyEes"sv));
    REQUIRE(xxx == s.find_last_not_of("Fobar GglyEes"));
    REQUIRE(xxx == s.substr(1, 1).find_last_not_of('F'));
    REQUIRE(xxx == s.find_last_not_of("o"sv, 100));
    REQUIRE(xxx == s.find_last_not_of("o", 100));
    REQUIRE(xxx == s.find_last_not_of("o", 100, 1));
    REQUIRE(xxx == s.find_last_not_of('o', 100));
}

TEST_CASE("std::string_view iterators")
{
    std::string_view s{"Hello, world!"};

    REQUIRE((std::is_same_v<decltype(s.begin()), XXX>));
    REQUIRE((std::is_same_v<decltype(s.cbegin()), XXX>));
    REQUIRE(xxx == *s.begin());
    REQUIRE(xxx == *(s.end() - 1));
    REQUIRE(xxx == *s.rbegin());
    REQUIRE(xxx == *(s.rend() - 1));
}
