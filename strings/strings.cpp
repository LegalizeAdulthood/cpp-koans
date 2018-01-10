#include "strings.h"

using namespace std::string_literals;

BOOST_AUTO_TEST_CASE(std_string_literals)
{
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
    std::string::iterator it6{xxx};
    auto res6 = s5.insert<std::string::iterator>(s5.begin(), s6.begin(), it6);
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
    std::string::iterator it4{xxx};
    s4.erase(it4, s4.end() - 1);
    BOOST_REQUIRE_EQUAL("H!"s, s4);
}

BOOST_AUTO_TEST_CASE(std_string_push_back)
{
    std::string s{"<"};
    char c{xxx};
    s.push_back(c);
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
    std::initializer_list<char> il{ xxx, xxx, xxx };
    s7.append(il);
    BOOST_REQUIRE_EQUAL("+--+"s, s7);
}

BOOST_AUTO_TEST_CASE(std_string_concatenation_operator)
{
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
    std::string s{"Canonical"};
    auto res = s.replace(xxx, xxx, "Med"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL("Medical"s, s);

    std::string::iterator first1{xxx};
    std::string::iterator last1{xxx};
    s.replace(first1, last1, "Gargantuan"s);
    BOOST_REQUIRE_EQUAL("Gargantuan"s, s);

    s.replace(xxx, xxx, " Two Face"s, xxx, xxx);
    BOOST_REQUIRE_EQUAL("Gargantua Two"s, s);

    s.replace(xxx, xxx, "Orion double"s, xxx);
    BOOST_REQUIRE_EQUAL("Gargantuan double"s, s);

    s.replace(xxx, xxx, "single minded", xxx);
    BOOST_REQUIRE_EQUAL("Gargantuan single"s, s);

    std::string::iterator first2{xxx};
    std::string::iterator last2{xxx};
    s.replace(first2, last2, "double sided", xxx);
    BOOST_REQUIRE_EQUAL("Gargantuan double"s, s);

    s.replace(xxx, xxx, "le carefully");
    BOOST_REQUIRE_EQUAL("Gargle carefully"s, s);

    std::string::iterator first3{xxx};
    std::string::iterator last3{xxx};
    s.replace(first3, last3, "is funny sometimes", xxx);
    BOOST_REQUIRE_EQUAL("Gargle is funny"s, s);

    s.replace(xxx, 4, xxx, '-');
    BOOST_REQUIRE_EQUAL("Gargle--funny"s, s);

    std::string::iterator first4{xxx};
    std::string::iterator last4{xxx};
    s.replace(first4, last4, 1, '!');
    BOOST_REQUIRE_EQUAL("Gargle!"s, s);

    std::string::iterator first5{xxx};
    std::string::iterator last5{xxx};
    std::initializer_list<char> il{ xxx, xxx, xxx };
    s.replace(first5, last5, il);
    BOOST_REQUIRE_EQUAL("Woo!", s);
}

BOOST_AUTO_TEST_CASE(std_string_substr)
{
    std::string s{"Holly Jolly Folly"};
    BOOST_REQUIRE_EQUAL(xxx, s.substr());

    BOOST_REQUIRE_EQUAL("Folly"s, s.substr(xxx));

    BOOST_REQUIRE_EQUAL("Jolly"s, s.substr(xxx, xxx));
}

BOOST_AUTO_TEST_CASE(std_string_copy)
{
    char dest[5];
    std::string s{"Holly Jolly Folly"};
    auto res = s.copy(dest, xxx);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(std::string(std::begin(dest), std::end(dest)), "Holly"s);
    BOOST_REQUIRE_EQUAL(xxx, res);

    char dest2[5];
    s.copy(dest2, xxx, xxx);
    BOOST_REQUIRE_EQUAL(std::string(std::begin(dest2), std::end(dest2)), "Jolly"s);

    BOOST_REQUIRE_THROW(s.copy(dest2, 0, std::string::npos), XXX);

    char dest3[80];
    auto res2 = s.copy(dest3, std::string::npos);
    BOOST_REQUIRE_EQUAL(xxx, res2);

    char dest4[5];
    s.copy(dest4, std::string::npos, xxx);
    BOOST_REQUIRE_EQUAL(std::string(std::begin(dest4), std::end(dest4)), "Folly"s);
}

BOOST_AUTO_TEST_CASE(std_string_resize)
{
    std::string s;
    s.resize(xxx);
    BOOST_REQUIRE_EQUAL("\0\0\0"s, s);

    s.resize(5, xxx);
    BOOST_REQUIRE_EQUAL("====="s, s);
}

BOOST_AUTO_TEST_CASE(std_string_swap)
{
    std::string s1{"Laurel"};
    std::string s2{"Hardy"};
    s1.swap(s2);
    BOOST_REQUIRE_EQUAL("xxx"s, s1);
    BOOST_REQUIRE_EQUAL("xxx"s, s2);
}

BOOST_AUTO_TEST_CASE(std_string_find)
{
    const std::string s{"Have a fun day at the zoo."};
    auto res = s.find("a"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    char ch{xxx};
    BOOST_REQUIRE_EQUAL(4, s.find(ch));
    BOOST_REQUIRE_EQUAL(6, s.find(ch, xxx));
    BOOST_REQUIRE_EQUAL(xxx, s.find("!"s));
    BOOST_REQUIRE_EQUAL(14, s.find(" a"s, xxx));
    BOOST_REQUIRE_EQUAL(xxx, s.find(" a"));
    BOOST_REQUIRE_EQUAL(14, s.find(" a", xxx));
    BOOST_REQUIRE_EQUAL(4, s.find(" a", xxx, 1));

    BOOST_REQUIRE_EQUAL(xxx, ""s.find(ch));
    BOOST_REQUIRE_EQUAL(xxx, "foo"s.find(ch, 10));
    BOOST_REQUIRE_EQUAL(xxx, "foo"s.find("f"s, 10));
    BOOST_REQUIRE_EQUAL(xxx, "foo"s.find("f", 10));
}

BOOST_AUTO_TEST_CASE(std_string_rfind)
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.rfind("oo"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo"s, 6));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo"));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo", 6));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind("oo", 6, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind('y'));
    BOOST_REQUIRE_EQUAL(xxx, s.rfind('y', 14));
}

BOOST_AUTO_TEST_CASE(std_string_find_first_of)
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_first_of("EGF"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF"s, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF", 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("EGF", 1, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o', 3));
    
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of(""s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of(""));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("ABC"s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("ABC"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('A'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o"s, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_find_first_not_of)
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_first_not_of("ABCDEFG"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("oab"s, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF", 3));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("abF", 3, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('o', 1));

    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("Fobar GglyEes"s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("Fobar GglyEes"));
    BOOST_REQUIRE_EQUAL(xxx, s.substr(1, 1).find_first_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o"s, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_first_not_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_find_last_of)
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_last_of("EGF"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF"s, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF", 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("EGF", 1, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o', 3));

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of(""s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of(""));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("ABC"s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("ABC"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('A'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o"s, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_of('o', 100));
}

BOOST_AUTO_TEST_CASE(std_string_find_last_not_of)
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_last_not_of("ABCDEFG"s);
    BOOST_REQUIRE((std::is_same_v<decltype(res), XXX>));
    BOOST_REQUIRE_EQUAL(xxx, res);

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("oab"s, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF"));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF", 3));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("abF", 3, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('o', 1));

    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("Fobar GglyEes"s));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("Fobar GglyEes"));
    BOOST_REQUIRE_EQUAL(xxx, s.substr(1, 1).find_last_not_of('F'));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o"s, 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o", 100));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of("o", 100, 1));
    BOOST_REQUIRE_EQUAL(xxx, s.find_last_not_of('o', 100));
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
