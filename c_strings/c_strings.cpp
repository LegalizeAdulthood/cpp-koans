#include "c_strings.h"

TEST_CASE("type of character literals")
{
    REQUIRE((std::is_same_v<decltype('a'), XXX>));
    REQUIRE((std::is_same_v<decltype(L'a'), XXX>));
    REQUIRE((std::is_same_v<decltype(u'a'), XXX>));
    REQUIRE((std::is_same_v<decltype(U'a'), XXX>));
    REQUIRE((std::is_same_v<decltype(u8'a'), XXX>));
}

TEST_CASE("special character literals")
{
    // see <https://en.wikipedia.org/wiki/File:USASCII_code_chart.png>
    REQUIRE(xxx == static_cast<int>('\020'));
    REQUIRE(xxx == static_cast<int>('\x20'));
    REQUIRE(xxx == static_cast<int>('\a'));
    REQUIRE(xxx == static_cast<int>('\b'));
    REQUIRE(xxx == static_cast<int>('\f'));
    REQUIRE(xxx == static_cast<int>('\n'));
    REQUIRE(xxx == static_cast<int>('\r'));
    REQUIRE(xxx == static_cast<int>('\t'));
    REQUIRE(xxx == static_cast<int>('\v'));
    REQUIRE(xxx == static_cast<int>('\''));
    REQUIRE(xxx == static_cast<int>('\"'));
    REQUIRE(xxx == static_cast<int>('\?'));
    REQUIRE(xxx == static_cast<int>('\\'));
    REQUIRE(xxx == static_cast<int>(L'\x1234'));
    REQUIRE(xxx == static_cast<int>(u'\u1234'));
    REQUIRE(xxx == static_cast<int>(U'\U00001E00'));
    REQUIRE(xxx == static_cast<int>(u8'A'));
}

TEST_CASE("type of string literals")
{
    auto s1{"Hello, world!"};
    auto s2{L"Hello, world!"};
    auto s3{u"Hello, world!"};
    auto s4{U"Hello, world!"};
    auto s5{u8"Hello, world!"};
    REQUIRE((std::is_same_v<decltype(s1), XXX>));
    REQUIRE((std::is_same_v<decltype(s2), XXX>));
    REQUIRE((std::is_same_v<decltype(s3), XXX>));
    REQUIRE((std::is_same_v<decltype(s4), XXX>));
    REQUIRE((std::is_same_v<decltype(s5), XXX>));
}

TEST_CASE("type of raw string literals")
{
    auto r1{R"one(Hello, world!)one"};
    auto r2{LR"two(Hello, world!)two"};
    auto r3{uR"three(Hello, world!)three"};
    auto r4{UR"four(Hello, world!)four"};
    auto r5{u8R"five(Hello, world!)five"};
    REQUIRE((std::is_same_v<decltype(r1), XXX>));
    REQUIRE((std::is_same_v<decltype(r2), XXX>));
    REQUIRE((std::is_same_v<decltype(r3), XXX>));
    REQUIRE((std::is_same_v<decltype(r4), XXX>));
    REQUIRE((std::is_same_v<decltype(r5), XXX>));
}

TEST_CASE("raw string literals")
{
    auto s{R"lit(
Hello, world!
)lit"};
    REQUIRE(xxx == s[0]);
}

TEST_CASE("begin end on character arrays")
{
    char s[]{"Hello, world!"};

    REQUIRE(xxx == std::begin(s));
    REQUIRE(xxx == std::end(s));
}
