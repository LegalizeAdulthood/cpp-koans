#include "strings.h"

using namespace std::string_literals;

TEST_CASE("std::string literals")
{
    auto s1{"Hello, world!"s};
    auto s2{L"Hello, world!"s};
    auto s3{u"Hello, world!"s};
    auto s4{U"Hello, world!"s};
    REQUIRE((std::is_same_v<decltype(s1), XXX>));
    REQUIRE((std::is_same_v<decltype(s2), XXX>));
    REQUIRE((std::is_same_v<decltype(s3), XXX>));
    REQUIRE((std::is_same_v<decltype(s4), XXX>));
}

TEST_CASE("std::string variants")
{
    REQUIRE((std::is_same_v<std::basic_string<char>, XXX>));
    REQUIRE((std::is_same_v<std::string, std::basic_string<XXX>>));
    REQUIRE((std::is_same_v<std::wstring, std::basic_string<XXX>>));
    REQUIRE((std::is_same_v<std::u16string, std::basic_string<XXX>>));
    REQUIRE((std::is_same_v<std::u32string, std::basic_string<XXX>>));
}

TEST_CASE("std::string related types")
{
    REQUIRE((std::is_same_v<std::string::traits_type, XXX>));
    REQUIRE((std::is_same_v<std::string::value_type, XXX>));
    REQUIRE((std::is_same_v<std::string::reference, XXX>));
    REQUIRE((std::is_same_v<std::string::const_reference, XXX>));
    REQUIRE((std::is_same_v<std::string::reverse_iterator, std::reverse_iterator<XXX>>));
    REQUIRE((std::is_same_v<std::string::const_reverse_iterator, std::reverse_iterator<XXX>>));
}

TEST_CASE("std::string constructors")
{
    std::string const s1;
    REQUIRE(xxx == s1.length());

    std::string const s2{5, 'E'};
    REQUIRE(xxx == s2.length());

    std::string const s3{s2};
    REQUIRE(xxx == s3.length());

    std::string const s4{s2, 1};
    REQUIRE(xxx == s4.length());

    std::string const hw{"Hello, world!"};
    std::string const s5{hw, 1, 4};
    REQUIRE(xxx == s5);

    std::string const s6{"Hello, world!"};
    REQUIRE(xxx == s6.length());

    std::string const s7{"Hello, world!", 5};
    REQUIRE(xxx == s7);

    std::string const s8{s7.begin(), s7.begin() + 1};
    REQUIRE(xxx == s8);

    std::string const s9{'H', 'e', 'l', 'l', 'o'};
    REQUIRE(xxx == s9);
}

TEST_CASE("std::string accessors")
{
    std::string const s{"Hello, world!"};

    REQUIRE(xxx == s[0]);
    REQUIRE('w' == s.at(xxx));
    REQUIRE_THROWS_AS(s.at(1000), XXX);
    REQUIRE(xxx == s.front());
    REQUIRE(xxx == s.back());
    REQUIRE((std::is_same_v<decltype(s.data()), XXX>));
    REQUIRE((std::is_same_v<decltype(s.c_str()), XXX>));
}

TEST_CASE("string_iterators")
{
    std::string const s{"Hello, world!"};
    REQUIRE((std::is_same_v<decltype(s.begin()), XXX>));
    REQUIRE((std::is_same_v<decltype(s.cbegin()), XXX>));
    REQUIRE(xxx == *s.begin());
    REQUIRE(xxx == *(s.end() - 1));
    REQUIRE(xxx == *s.rbegin());
    REQUIRE(xxx == *(s.rend() - 1));
}

TEST_CASE("std::string capacity")
{
    std::string s{"Hello, world!"};
    REQUIRE(xxx == s.length());
    REQUIRE(xxx == s.empty());
    REQUIRE(static_cast<std::string::size_type>(xxx) >= s.capacity());

    s += s;
    s = "Hello, world!";
    REQUIRE(xxx == s.length());
    REQUIRE(static_cast<std::string::size_type>(xxx) >= s.capacity());

    s.shrink_to_fit();
    REQUIRE(xxx == s.length());
    REQUIRE(static_cast<std::string::size_type>(xxx) >= s.capacity());

    s.reserve(1024);
    REQUIRE(xxx == s.length());
    REQUIRE(xxx == s.capacity());
}

TEST_CASE("std::string clear")
{
    std::string s{"Hello, world!"};
    s.clear();
    REQUIRE(xxx == s.length());
    REQUIRE(xxx == s.empty());
    REQUIRE(s.capacity() >= static_cast<std::string::size_type>(xxx));
}

TEST_CASE("std::string insert")
{
    std::string s2{"Bob"};
    auto res1 = s2.insert(1, "illy B");
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == s2);

    auto res2 = s2.insert(0, 2, '-');
    REQUIRE((std::is_same_v<decltype(res2), XXX>));
    REQUIRE(xxx == s2);

    auto res3 = s2.insert(2, "Hello, world!", 7);
    REQUIRE((std::is_same_v<decltype(res3), XXX>));
    REQUIRE(xxx == s2);

    std::string s3{"Hello, world!"};
    std::string s4{"big, fat "};
    auto res4 = s3.insert(7, s4);
    REQUIRE((std::is_same_v<decltype(res4), XXX>));
    REQUIRE(xxx == s3);

    std::string s5{"Hello, world!"};
    auto res5 = s5.insert(7, s4, xxx, 3);
    REQUIRE((std::is_same_v<decltype(res5), XXX>));
    REQUIRE("Hello, fat world!"s == s5);

    std::string s6{"Hello? "};
    std::string::iterator it6{xxx};
    auto res6 = s5.insert<std::string::iterator>(s5.begin(), s6.begin(), it6);
    REQUIRE((std::is_same_v<decltype(res6), XXX>));
    REQUIRE("Hello? Hello, fat world!"s == s5);
    REQUIRE(xxx == *res6);

    std::string s7{", world"};
    auto res7 = s7.insert(0, {'H', 'e', 'l', 'l', 'o'});
    REQUIRE((std::is_same_v<decltype(res7), XXX>));
    REQUIRE(xxx == s7);
}

TEST_CASE("std::string erase")
{
    std::string s1{"Hello, world!"};
    s1.erase(5);
    REQUIRE(xxx == s1);

    std::string s2{"Hello, world!"};
    s2.erase(5, 1);
    REQUIRE(xxx == s2);

    std::string s3{"Hello, world!"};
    s3.erase(s3.end() - 1);
    REQUIRE(xxx == s3);

    std::string s4{"Hello, world!"};
    std::string::iterator it4{xxx};
    s4.erase(it4, s4.end() - 1);
    REQUIRE("H!"s == s4);
}

TEST_CASE("std::string push_back")
{
    std::string s{"<"};
    char c{xxx};
    s.push_back(c);
    REQUIRE("<>"s == s);
}

TEST_CASE("std::string pop_back")
{
    std::string s{"[]"};
    s.pop_back();
    REQUIRE(xxx == s);
}

TEST_CASE("std::string append")
{
    std::string s1{"<["};
    auto res1 = s1.append(xxx, 2);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE("<[]>"s == s1);

    std::string s2{"Foo"};
    s2.append("bar"s);
    REQUIRE(xxx == s2);

    std::string s3{"Meta"};
    s3.append("Well, what about the--"s, xxx);
    REQUIRE("Meta--"s == s3);

    std::string s4{"Wafer "};
    s4.append("Something"s, 4, xxx);
    REQUIRE("Wafer thin"s == s4);

    std::string s5{"The good "};
    s5.append(" wicked witch", xxx);
    REQUIRE("The good witch"s == s5);

    std::string s6{"Powdered "};
    const char lit[] = "donut";
    s6.append(std::begin(lit), xxx);
    REQUIRE("Powdered donut"s == s6);

    std::string s7{"+"};
    std::initializer_list<char> il{ xxx, xxx, xxx };
    s7.append(il);
    REQUIRE("+--+"s == s7);
}

TEST_CASE("std::string operator+")
{
    std::string s1{"One"};
    std::string s2{s1 + static_cast<char>(xxx)};
    REQUIRE("One!"s == s2);

    std::string s3{static_cast<char>(xxx) + s2};
    REQUIRE("!One!"s == s3);

    std::string s4{"One, "};
    std::string s5{xxx};
    std::string s6{s4 + s5};
    REQUIRE("One, Two"s == s6);

    const char *lit = "Ten";
    std::string s7{s4 + lit};
    REQUIRE(xxx == s7);
}

TEST_CASE("std::string comparison operators")
{
    const std::string alpha{"Alpha"};
    REQUIRE("xxx"s < alpha);
    REQUIRE("xxx"s > alpha);
    REQUIRE("xxx"s <= alpha);
    REQUIRE("xxx"s >= alpha);
    REQUIRE("xxx"s == alpha);
    REQUIRE("xxx"s != alpha);
}

TEST_CASE("std::string compare")
{
    const std::string s1{"Alphabetical"};
    const std::string s2{"Alphanumerical"};
    auto res1 = s1.compare(s2);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == res1);

    REQUIRE(0 == s1.compare(xxx, 5, s2));
    REQUIRE(0 == s1.compare(xxx, 3, s2, 11, 3));
    REQUIRE(0 == s1.compare("xxx"));
    REQUIRE(0 == s1.compare(xxx, 4, "ical"));
    REQUIRE(0 == s1.compare(xxx, 4, "Canonical", 5));
}

TEST_CASE("std::string replace")
{
    std::string s{"Canonical"};
    auto res = s.replace(xxx, xxx, "Med"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE("Medical"s == s);

    std::string::iterator first1{xxx};
    std::string::iterator last1{xxx};
    s.replace(first1, last1, "Gargantuan"s);
    REQUIRE("Gargantuan"s == s);

    s.replace(xxx, xxx, " Two Face"s, xxx, xxx);
    REQUIRE("Gargantua Two"s == s);

    s.replace(xxx, xxx, "Orion double"s, xxx);
    REQUIRE("Gargantuan double"s == s);

    s.replace(xxx, xxx, "single minded", xxx);
    REQUIRE("Gargantuan single"s == s);

    std::string::iterator first2{xxx};
    std::string::iterator last2{xxx};
    s.replace(first2, last2, "double sided", xxx);
    REQUIRE("Gargantuan double"s == s);

    s.replace(xxx, xxx, "le carefully");
    REQUIRE("Gargle carefully"s == s);

    std::string::iterator first3{xxx};
    std::string::iterator last3{xxx};
    s.replace(first3, last3, "is funny sometimes", xxx);
    REQUIRE("Gargle is funny"s == s);

    s.replace(xxx, 4, xxx, '-');
    REQUIRE("Gargle--funny"s == s);

    std::string::iterator first4{xxx};
    std::string::iterator last4{xxx};
    s.replace(first4, last4, 1, '!');
    REQUIRE("Gargle!"s == s);

    std::string::iterator first5{xxx};
    std::string::iterator last5{xxx};
    s.replace(first5, last5, std::initializer_list<char>{ xxx, xxx, xxx });
    REQUIRE("Woo!"s == s);
}

TEST_CASE("std::string substr")
{
    std::string s{"Holly Jolly Folly"};
    REQUIRE(xxx == s.substr());

    REQUIRE("Folly"s == s.substr(xxx));

    REQUIRE("Jolly"s == s.substr(xxx, xxx));
}

TEST_CASE("std::string copy")
{
    char dest[5];
    std::string s{"Holly Jolly Folly"};
    auto res = s.copy(dest, xxx);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(std::string(std::begin(dest), std::end(dest)) == "Holly"s);
    REQUIRE(xxx == res);

    char dest2[5];
    s.copy(dest2, xxx, xxx);
    REQUIRE(std::string(std::begin(dest2), std::end(dest2)) == "Jolly"s);

    REQUIRE_THROWS_AS(s.copy(dest2, 0, std::string::npos), XXX);

    char dest3[80];
    auto res2 = s.copy(dest3, std::string::npos);
    REQUIRE(xxx == res2);

    char dest4[5];
    s.copy(dest4, std::string::npos, xxx);
    REQUIRE(std::string(std::begin(dest4), std::end(dest4)) == "Folly"s);
}

TEST_CASE("std::string resize")
{
    std::string s;
    s.resize(xxx);
    REQUIRE("\0\0\0"s == s);

    s.resize(5, xxx);
    REQUIRE("====="s == s);
}

TEST_CASE("std::string swap")
{
    std::string s1{"Laurel"};
    std::string s2{"Hardy"};
    s1.swap(s2);
    REQUIRE("xxx"s == s1);
    REQUIRE("xxx"s == s2);
}

TEST_CASE("std::string find")
{
    const std::string s{"Have a fun day at the zoo."};
    auto res = s.find("a"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    char ch{xxx};
    REQUIRE(4 == s.find(ch));
    REQUIRE(6 == s.find(ch, xxx));
    REQUIRE(xxx == s.find("!"s));
    REQUIRE(14 == s.find(" a"s, xxx));
    REQUIRE(xxx == s.find(" a"));
    REQUIRE(14 == s.find(" a", xxx));
    REQUIRE(4 == s.find(" a", xxx, 1));

    REQUIRE(xxx == ""s.find(ch));
    REQUIRE(xxx == "foo"s.find(ch, 10));
    REQUIRE(xxx == "foo"s.find("f"s, 10));
    REQUIRE(xxx == "foo"s.find("f", 10));
}

TEST_CASE("std::string rfind")
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.rfind("oo"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.rfind("oo"s, 6));
    REQUIRE(xxx == s.rfind("oo"));
    REQUIRE(xxx == s.rfind("oo", 6));
    REQUIRE(xxx == s.rfind("oo", 6, 1));
    REQUIRE(xxx == s.rfind('y'));
    REQUIRE(xxx == s.rfind('y', 14));
}

TEST_CASE("std::string find_first_of")
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_first_of("EGF"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_first_of("EGF"s, 1));
    REQUIRE(xxx == s.find_first_of("EGF"));
    REQUIRE(xxx == s.find_first_of("EGF", 1));
    REQUIRE(xxx == s.find_first_of("EGF", 1, 1));
    REQUIRE(xxx == s.find_first_of('o'));
    REQUIRE(xxx == s.find_first_of('o', 3));
    
    REQUIRE(xxx == s.find_first_of(""s));
    REQUIRE(xxx == s.find_first_of(""));
    REQUIRE(xxx == s.find_first_of("ABC"s));
    REQUIRE(xxx == s.find_first_of("ABC"));
    REQUIRE(xxx == s.find_first_of('A'));
    REQUIRE(xxx == s.find_first_of("o"s, 100));
    REQUIRE(xxx == s.find_first_of("o", 100));
    REQUIRE(xxx == s.find_first_of("o", 100, 1));
    REQUIRE(xxx == s.find_first_of('o', 100));
}

TEST_CASE("std::string find_first_not_of")
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_first_not_of("ABCDEFG"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_first_not_of("oab"s, 1));
    REQUIRE(xxx == s.find_first_not_of("abF"));
    REQUIRE(xxx == s.find_first_not_of("abF", 3));
    REQUIRE(xxx == s.find_first_not_of("abF", 3, 1));
    REQUIRE(xxx == s.find_first_not_of('F'));
    REQUIRE(xxx == s.find_first_not_of('o', 1));

    REQUIRE(xxx == s.find_first_not_of("Fobar GglyEes"s));
    REQUIRE(xxx == s.find_first_not_of("Fobar GglyEes"));
    REQUIRE(xxx == s.substr(1, 1).find_first_not_of('F'));
    REQUIRE(xxx == s.find_first_not_of("o"s, 100));
    REQUIRE(xxx == s.find_first_not_of("o", 100));
    REQUIRE(xxx == s.find_first_not_of("o", 100, 1));
    REQUIRE(xxx == s.find_first_not_of('o', 100));
}

TEST_CASE("std::string find_last_of")
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_last_of("EGF"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_last_of("EGF"s, 1));
    REQUIRE(xxx == s.find_last_of("EGF"));
    REQUIRE(xxx == s.find_last_of("EGF", 1));
    REQUIRE(xxx == s.find_last_of("EGF", 1, 1));
    REQUIRE(xxx == s.find_last_of('o'));
    REQUIRE(xxx == s.find_last_of('o', 3));

    REQUIRE(xxx == s.find_last_of(""s));
    REQUIRE(xxx == s.find_last_of(""));
    REQUIRE(xxx == s.find_last_of("ABC"s));
    REQUIRE(xxx == s.find_last_of("ABC"));
    REQUIRE(xxx == s.find_last_of('A'));
    REQUIRE(xxx == s.find_last_of("o"s, 100));
    REQUIRE(xxx == s.find_last_of("o", 100));
    REQUIRE(xxx == s.find_last_of("o", 100, 1));
    REQUIRE(xxx == s.find_last_of('o', 100));
}

TEST_CASE("std::string find_last_not_of")
{
    std::string s{"Foobar Googly Eyes"};
    auto res = s.find_last_not_of("ABCDEFG"s);
    REQUIRE((std::is_same_v<decltype(res), XXX>));
    REQUIRE(xxx == res);

    REQUIRE(xxx == s.find_last_not_of("oab"s, 1));
    REQUIRE(xxx == s.find_last_not_of("abF"));
    REQUIRE(xxx == s.find_last_not_of("abF", 3));
    REQUIRE(xxx == s.find_last_not_of("abF", 3, 1));
    REQUIRE(xxx == s.find_last_not_of('F'));
    REQUIRE(xxx == s.find_last_not_of('o', 1));

    REQUIRE(xxx == s.find_last_not_of("Fobar GglyEes"s));
    REQUIRE(xxx == s.find_last_not_of("Fobar GglyEes"));
    REQUIRE(xxx == s.substr(1, 1).find_last_not_of('F'));
    REQUIRE(xxx == s.find_last_not_of("o"s, 100));
    REQUIRE(xxx == s.find_last_not_of("o", 100));
    REQUIRE(xxx == s.find_last_not_of("o", 100, 1));
    REQUIRE(xxx == s.find_last_not_of('o', 100));
}

TEST_CASE("std::string signed integer conversions")
{
    auto res1 = std::stoi("111"s);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == res1);
    auto res2 = std::stol("222"s);
    REQUIRE((std::is_same_v<decltype(res2), XXX>));
    REQUIRE(xxx == res2);
    auto res3 = std::stoll("333"s);
    REQUIRE((std::is_same_v<decltype(res3), XXX>));
    REQUIRE(xxx == res3);

    REQUIRE(xxx == std::stoi(L"111"s));
    REQUIRE(xxx == std::stol(L"222"s));
    REQUIRE(xxx == std::stoll(L"333"s));

    REQUIRE(xxx == std::stoi(" \t\v\r\n\f111"s));
    REQUIRE(xxx == std::stol(" \t\v\r\n\f222"s));
    REQUIRE(xxx == std::stoll(" \t\v\r\n\f333"s));

    REQUIRE(xxx == std::stoi("-1"));
    REQUIRE(xxx == std::stoi("+1"));

    std::size_t pos = 0;
    REQUIRE(xxx == std::stoi("100x"s, &pos));
    REQUIRE(xxx == pos);

    for( int base = 2; base <= 36; ++base)
    {
        REQUIRE(xxx == std::stoi("10", nullptr, base));
    }

    REQUIRE(xxx == std::stoi("10", nullptr, 0));
    REQUIRE(xxx == std::stoi("010", nullptr, 0));
    REQUIRE(xxx == std::stoi("010", nullptr, 8));
    REQUIRE(xxx == std::stoi("0x10", nullptr, 0));
    REQUIRE(xxx == std::stoi("0X10", nullptr, 0));
    REQUIRE(xxx == std::stoi("0x10", nullptr, 16));
    REQUIRE(xxx == std::stoi("0xa", nullptr, 16));
    REQUIRE(xxx == std::stoi("0xA", nullptr, 16));

    REQUIRE_THROWS_AS(std::stoi("Yikes!"), XXX);
    REQUIRE_THROWS_AS(std::stoi("0xFFFFFFFFFFFFFFFFFFFFFFFF", nullptr, 16), XXX);
}

TEST_CASE("std::string unsigned integer conversions")
{
    auto res1 = std::stoul("111"s);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == res1);
    auto res2 = std::stoull("222"s);
    REQUIRE((std::is_same_v<decltype(res2), XXX>));
    REQUIRE(xxx == res2);

    REQUIRE(xxx == std::stoul(L"111"s));
    REQUIRE(xxx == std::stoull(L"222"s));

    REQUIRE(xxx == std::stoul(" \t\v\r\n\f111"s));
    REQUIRE(xxx == std::stoull(" \t\v\r\n\f222"s));

    REQUIRE(xxx == std::stoul("-1"));
    REQUIRE(xxx == std::stoul("+1"));

    std::size_t pos = 0;
    REQUIRE(xxx == std::stoul("100x"s, &pos));
    REQUIRE(xxx == pos);

    for( int base = 2; base <= 36; ++base)
    {
        REQUIRE(xxx == std::stoul("10", nullptr, base));
    }

    REQUIRE(xxx == std::stoul("10", nullptr, 0));
    REQUIRE(xxx == std::stoul("010", nullptr, 0));
    REQUIRE(xxx == std::stoul("010", nullptr, 8));
    REQUIRE(xxx == std::stoul("0x10", nullptr, 0));
    REQUIRE(xxx == std::stoul("0X10", nullptr, 0));
    REQUIRE(xxx == std::stoul("0x10", nullptr, 16));

    REQUIRE_THROWS_AS(std::stoul("Yikes!"), XXX);
    REQUIRE_THROWS_AS(std::stoul("0xFFFFFFFFFFFFFFFFFFFFFFFF", nullptr, 16), XXX);
}

TEST_CASE("std::string float conversions")
{
    auto res1 = std::stof("111"s);
    REQUIRE((std::is_same_v<decltype(res1), XXX>));
    REQUIRE(xxx == res1);
    auto res2 = std::stod("222"s);
    REQUIRE((std::is_same_v<decltype(res2), XXX>));
    REQUIRE(xxx == res2);

    REQUIRE(xxx == std::stof(L"111"s));
    REQUIRE(xxx == std::stod(L"222"s));

    REQUIRE(xxx == std::stof(" \t\v\r\n\f111"s));
    REQUIRE(xxx == std::stod(" \t\v\r\n\f222"s));

    REQUIRE(xxx == std::stof("-1.5e1"));
    REQUIRE(xxx == std::stof("+1.5E1"));
    REQUIRE(xxx == std::stof("inf"));
    REQUIRE(xxx == std::stof("-INFINITY"));
    REQUIRE(xxx == std::stof("+nan"));
    REQUIRE(xxx == std::stof("-nanotechnology"));

    std::size_t pos = 0;
    REQUIRE(xxx == std::stof("100x"s, &pos));
    REQUIRE(xxx == pos);

    REQUIRE_THROWS_AS(std::stof("Yikes!"), XXX);
    REQUIRE_THROWS_AS(std::stof("0xFFFFFFFFFFFFFFFFFFFFFFFF", nullptr), XXX);
}

TEST_CASE("std::string to_string function")
{
    REQUIRE((std::is_same_v<decltype(std::to_string(1)), XXX>));
    REQUIRE((std::is_same_v<decltype(std::to_wstring(1)), XXX>));
    REQUIRE("xxx"s == std::to_string(-1));
    REQUIRE("xxx"s == std::to_string(2L));
    REQUIRE("xxx"s == std::to_string(3LL));
    REQUIRE("xxx"s == std::to_string(4U));
    REQUIRE("xxx"s == std::to_string(5UL));
    REQUIRE("xxx"s == std::to_string(6ULL));
    REQUIRE("xxx"s == std::to_string(23.43f));
    REQUIRE("xxx"s == std::to_string(23.43));
    REQUIRE("xxx"s == std::to_string(23.43L));
    REQUIRE("xxx"s == std::to_string(1e-40));
}

TEST_CASE("std::string allocators")
{
    REQUIRE((std::is_same_v<std::string::allocator_type, XXX>));
    REQUIRE((std::is_same_v<std::string::size_type, XXX>));
    REQUIRE((std::is_same_v<std::string::difference_type, XXX>));
    REQUIRE((std::is_same_v<std::string::pointer, XXX>));
    REQUIRE((std::is_same_v<std::string::const_pointer, XXX>));
}
