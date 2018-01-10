#include "strings.h"

BOOST_AUTO_TEST_CASE(std_string_literals)
{
    using namespace std::string_literals;
    auto s1{"Hello, world!"s};
    auto s2{L"Hello, world!"s};
    auto s3{u"Hello, world!"s};
    auto s4{U"Hello, world!"s};
    BOOST_REQUIRE((std::is_same_v<decltype(s1), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s2), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s3), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s4), XXX>));
}

BOOST_AUTO_TEST_CASE(std_string_variants)
{
    BOOST_REQUIRE((std::is_same_v<std::basic_string<char>, XXX>));
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

BOOST_AUTO_TEST_CASE(std_string_accessors)
{
    std::string const s{"Hello, world!"};

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
    std::string const s{"Hello, world!"};
    BOOST_REQUIRE((std::is_same_v<decltype(s.begin()), XXX>));
    BOOST_REQUIRE((std::is_same_v<decltype(s.cbegin()), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, *s.begin());
    BOOST_REQUIRE_EQUAL(xxx, *(s.end() - 1));
    BOOST_REQUIRE_EQUAL(xxx, *s.rbegin());
    BOOST_REQUIRE_EQUAL(xxx, *(s.rend() - 1));
}

BOOST_AUTO_TEST_CASE(std_string_capacity)
{
    std::string s{"Hello, world!"};
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_EQUAL(xxx, s.empty());
    BOOST_REQUIRE_GE(static_cast<std::string::size_type>(xxx), s.capacity());

    s += s;
    s = "Hello, world!";
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_GE(static_cast<std::string::size_type>(xxx), s.capacity());

    s.shrink_to_fit();
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_GE(static_cast<std::string::size_type>(xxx), s.capacity());

    s.reserve(1024);
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_EQUAL(xxx, s.capacity());
}

BOOST_AUTO_TEST_CASE(std_string_clear)
{
    std::string s{"Hello, world!"};
    s.clear();
    BOOST_REQUIRE_EQUAL(xxx, s.length());
    BOOST_REQUIRE_EQUAL(xxx, s.empty());
    BOOST_REQUIRE_GE(s.capacity(), static_cast<std::string::size_type>(xxx));
}

BOOST_AUTO_TEST_CASE(std_string_insert)
{
    using namespace std::string_literals;

    std::string s2{"Bob"};
    auto res1 = s2.insert(1, "illy B");
    BOOST_REQUIRE((std::is_same_v<decltype(res1), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, s2);

    auto res2 = s2.insert(0, 2, '-');
    BOOST_REQUIRE((std::is_same_v<decltype(res2), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, s2);

    auto res3 = s2.insert(2, "Hello, world!", 7);
    BOOST_REQUIRE((std::is_same_v<decltype(res3), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, s2);

    std::string s3{"Hello, world!"};
    std::string s4{"big, fat "};
    auto res4 = s3.insert(7, s4);
    BOOST_REQUIRE((std::is_same_v<decltype(res4), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, s3);

    std::string s5{"Hello, world!"};
    auto res5 = s5.insert(7, s4, xxx, 3);
    BOOST_REQUIRE((std::is_same_v<decltype(res5), XXX>));
    BOOST_REQUIRE_EQUAL("Hello, fat world!"s, s5);

    std::string s6{"Hello? "};
    auto res6 = s5.insert<std::string::iterator>(s5.begin(), s6.begin(), xxx);
    BOOST_REQUIRE((std::is_same_v<decltype(res6), XXX>));
    BOOST_REQUIRE_EQUAL("Hello? Hello, fat world!"s, s5);
    BOOST_REQUIRE_EQUAL(xxx, *res6);

    std::string s7{", world"};
    auto res7 = s7.insert(0, {'H', 'e', 'l', 'l', 'o'});
    BOOST_REQUIRE((std::is_same_v<decltype(res7), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, s7);
}

BOOST_AUTO_TEST_CASE(std_string_erase)
{
    using namespace std::string_literals;
    std::string s1{"Hello, world!"};
    s1.erase(5);
    BOOST_REQUIRE_EQUAL(xxx, s1);

    std::string s2{"Hello, world!"};
    s2.erase(5, 1);
    BOOST_REQUIRE_EQUAL(xxx, s2);

    std::string s3{"Hello, world!"};
    s3.erase(s3.end() - 1);
    BOOST_REQUIRE_EQUAL(xxx, s3);

    std::string s4{"Hello, world!"};
    s4.erase(xxx, s4.end() - 1);
    BOOST_REQUIRE_EQUAL("H!"s, s4);
}

BOOST_AUTO_TEST_CASE(std_string_push_back)
{
    using namespace std::string_literals;
    std::string s{"<"};
    s.push_back(xxx);
    BOOST_REQUIRE_EQUAL("<>"s, s);
}

BOOST_AUTO_TEST_CASE(std_string_pop_back)
{
    std::string s{"[]"};
    s.pop_back();
    BOOST_REQUIRE_EQUAL(xxx, s);
}

BOOST_AUTO_TEST_CASE(std_string_append)
{
    using namespace std::string_literals;
    std::string s1{"<["};
    auto res1 = s1.append(xxx, 2);
    BOOST_REQUIRE((std::is_same_v<decltype(res1), XXX>));
    BOOST_REQUIRE_EQUAL("<[]>"s, s1);

    std::string s2{"Foo"};
    s2.append("bar"s);
    BOOST_REQUIRE_EQUAL(xxx, s2);

    std::string s3{"Meta"};
    s3.append("Well, what about the--"s, xxx);
    BOOST_REQUIRE_EQUAL("Meta--"s, s3);

    std::string s4{"Wafer "};
    s4.append("Something"s, 4, xxx);
    BOOST_REQUIRE_EQUAL("Wafer thin"s, s4);

    std::string s5{"The good "};
    s5.append(" wicked witch", xxx);
    BOOST_REQUIRE_EQUAL("The good witch"s, s5);

    std::string s6{"Powdered "};
    const char lit[] = "donut";
    s6.append(std::begin(lit), xxx);
    BOOST_REQUIRE_EQUAL("Powdered donut"s, s6);

    std::string s7{"+"};
    s7.append({ xxx, xxx, xxx });
    BOOST_REQUIRE_EQUAL("+--+"s, s7);
}

BOOST_AUTO_TEST_CASE(std_string_concatenation_operator)
{
    using namespace std::string_literals;
    std::string s1{"One"};
    std::string s2{s1 + static_cast<char>(xxx)};
    BOOST_REQUIRE_EQUAL("One!"s, s2);

    std::string s3{static_cast<char>(xxx) + s2};
    BOOST_REQUIRE_EQUAL("!One!"s, s3);

    std::string s4{"One, "};
    std::string s5{xxx};
    std::string s6{s4 + s5};
    BOOST_REQUIRE_EQUAL("One, Two"s, s6);

    const char *lit = "Ten";
    std::string s7{s4 + lit};
    BOOST_REQUIRE_EQUAL(xxx, s7);
}

BOOST_AUTO_TEST_CASE(std_string_comparison_operators)
{
    using namespace std::string_literals;
    const std::string alpha{"Alpha"};
    const std::string beta{"Beta"};
    bool lt = static_cast<std::string>(xxx) < beta;
    BOOST_REQUIRE(lt);

    bool gt = static_cast<std::string>(xxx) > beta;
    BOOST_REQUIRE(gt);

    bool le = static_cast<std::string>(xxx) <= beta;
    bool ge = static_cast<std::string>(xxx) >= beta;
    BOOST_REQUIRE(le && ge);

    bool eq = static_cast<std::string>(xxx) == alpha;
    BOOST_REQUIRE(eq);

    bool ne = static_cast<std::string>(xxx) != alpha;
    BOOST_REQUIRE(ne);
}

BOOST_AUTO_TEST_CASE(std_string_compare)
{
    using namespace std::string_literals;
    const std::string s1{"Alphabetical"};
    const std::string s2{"Alphanumerical"};
    auto res1 = s1.compare(s2);
    BOOST_REQUIRE((std::is_same_v<decltype(res1), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res1);

    auto res2 = s1.compare(xxx, 5, s2);
    BOOST_REQUIRE_EQUAL(0, res2);

    auto res3 = s1.compare(xxx, 3, s2, 11, 3);
    BOOST_REQUIRE_EQUAL(0, res3);

    auto res4 = s1.compare("xxx");
    BOOST_REQUIRE_EQUAL(0, res4);

    auto res5 = s1.compare(xxx, 4, "ical");
    BOOST_REQUIRE_EQUAL(0, res5);

    auto res6 = s1.compare(xxx, 4, "Canonical", 5);
    BOOST_REQUIRE_EQUAL(0, res6);
}

BOOST_AUTO_TEST_CASE(std_string_replace)
{
}

BOOST_AUTO_TEST_CASE(std_string_substr)
{
}

BOOST_AUTO_TEST_CASE(std_string_copy)
{
}

BOOST_AUTO_TEST_CASE(std_string_resize)
{
}

BOOST_AUTO_TEST_CASE(std_string_swap)
{
}

BOOST_AUTO_TEST_CASE(std_string_find)
{
}

BOOST_AUTO_TEST_CASE(std_string_rfind)
{
}

BOOST_AUTO_TEST_CASE(std_string_find_first_of)
{
}

BOOST_AUTO_TEST_CASE(std_string_find_first_not_of)
{
}

BOOST_AUTO_TEST_CASE(std_string_find_last_of)
{
}

BOOST_AUTO_TEST_CASE(std_string_find_last_not_of)
{
}

BOOST_AUTO_TEST_CASE(std_string_conversions)
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
