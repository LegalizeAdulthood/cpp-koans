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
    s2.insert(1, "illy B");
    BOOST_REQUIRE_EQUAL(xxx, s2);

    s2.insert(0, 2, '-');
    BOOST_REQUIRE_EQUAL(xxx, s2);

    s2.insert(2, "Hello, world!", 7);
    BOOST_REQUIRE_EQUAL(xxx, s2);

    std::string s3{"Hello, world!"};
    std::string s4{"big, fat "};
    s3.insert(7, s4);
    BOOST_REQUIRE_EQUAL(xxx, s3);

    std::string s5{"Hello, world!"};
    s5.insert(7, s4, xxx, 3);
    BOOST_REQUIRE_EQUAL("Hello, fat world!"s, s5);

    std::string s6{"Hello? "};
    std::string::iterator pos = s5.insert<std::string::iterator>(s5.begin(), s6.begin(), xxx);
    BOOST_REQUIRE_EQUAL("Hello? Hello, fat world!"s, s5);
    BOOST_REQUIRE_EQUAL(xxx, *pos);

    std::string s7{", world"};
    s7.insert(0, {'H', 'e', 'l', 'l', 'o'});
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
}

BOOST_AUTO_TEST_CASE(std_string_pop_back)
{
}

BOOST_AUTO_TEST_CASE(std_string_append)
{
}

BOOST_AUTO_TEST_CASE(std_string_operators)
{
}

BOOST_AUTO_TEST_CASE(std_string_compare)
{
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
