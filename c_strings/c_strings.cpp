#include "c_strings.h"

BOOST_AUTO_TEST_SUITE(character_literals)

BOOST_AUTO_TEST_CASE(type_of_character_literals)
{
    BOOST_REQUIRE((std::is_same_v<decltype('a'), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(L'a'), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(u'a'), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(U'a'), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(u8'a'), XXX>));
}

BOOST_AUTO_TEST_CASE(special_character_literals)
{
    // see <https://en.wikipedia.org/wiki/File:USASCII_code_chart.png>
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\020'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\x20'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\a'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\b'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\f'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\n'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\r'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\t'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\v'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\''));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\"'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\?'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>('\\'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>(L'\x1234'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>(u'\u1234'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>(U'\U00001E00'));
    BOOST_REQUIRE_EQUAL(xxx, static_cast<int>(u8'A'));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(string_literals)

BOOST_AUTO_TEST_CASE(type_of_string_literal)
{
    auto s1{"Hello, world!"};
    auto s2{L"Hello, world!"};
    auto s3{u"Hello, world!"};
    auto s4{U"Hello, world!"};
    auto s5{u8"Hello, world!"};
    BOOST_REQUIRE((std::is_same_v<decltype(s1), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s2), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s3), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s4), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s5), XXX>));
}

BOOST_AUTO_TEST_CASE(type_of_raw_string_literals)
{
    auto r1{R"one(Hello, world!)one"};
    auto r2{LR"two(Hello, world!)two"};
    auto r3{uR"three(Hello, world!)three"};
    auto r4{UR"four(Hello, world!)four"};
    auto r5{u8R"five(Hello, world!)five"};
    BOOST_REQUIRE((std::is_same_v<decltype(r1), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(r2), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(r3), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(r4), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(r5), XXX>));
}

BOOST_AUTO_TEST_CASE(raw_string_literals)
{
    auto s{R"lit(
Hello, world!
)lit"};
    BOOST_REQUIRE_EQUAL(xxx, s[0]);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(c_strings)

BOOST_AUTO_TEST_CASE(begin_end_on_character_arrays)
{
    char s[]{"Hello, world!"};

    BOOST_REQUIRE_EQUAL(xxx, std::begin(s));
    BOOST_REQUIRE_EQUAL(xxx, std::end(s));
}

BOOST_AUTO_TEST_SUITE_END()
