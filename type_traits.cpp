#include "type_traits.h"
#include <type_traits>

// In each test, replace XXX with syntax that passes the test.

BOOST_AUTO_TEST_CASE(is_void)
{
    BOOST_REQUIRE_EQUAL(true, std::is_void<XXX>::value);
    std::is_void<XXX> val;
    BOOST_REQUIRE_EQUAL(true, static_cast<bool>(val));
}

BOOST_AUTO_TEST_CASE(is_integral)
{
    BOOST_REQUIRE_EQUAL(true, std::is_integral<XXX>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<int &>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<int *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype('!')>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(false)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(666ULL)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(0.)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(0.f)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype("Hello, world!")>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(L'!')>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(L"Hello, world!")>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<decltype(R"(Hello, "world"!)")>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_integral<const int>::value);
}

BOOST_AUTO_TEST_CASE(is_floating_point)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<float>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<double>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<long double>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<decltype(0 + 1.)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<decltype(0. + 1)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_floating_point<decltype(0 + 1)>::value);
}

BOOST_AUTO_TEST_CASE(is_array)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_array<int>::value);
    typedef std::array<int, 10> std_array;
    BOOST_REQUIRE_EQUAL(xxx, std::is_array<std_array>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_array<int *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_array<int &>::value);
    BOOST_REQUIRE_EQUAL(true, std::is_array<XXX>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_array<int *[10]>::value);
}

BOOST_AUTO_TEST_CASE(is_enum)
{
    BOOST_REQUIRE_EQUAL(true, std::is_enum<XXX>::value);
}

BOOST_AUTO_TEST_CASE(is_union)
{
    BOOST_REQUIRE_EQUAL(true, std::is_union<XXX>::value);
    struct S {};
    BOOST_REQUIRE_EQUAL(xxx, std::is_union<S>::value);
}

BOOST_AUTO_TEST_CASE(is_class)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_class<int>::value);
    struct S {};
    BOOST_REQUIRE_EQUAL(xxx, std::is_class<S>::value);
    class C {};
    BOOST_REQUIRE_EQUAL(xxx, std::is_class<C>::value);
    union U {};
    BOOST_REQUIRE_EQUAL(xxx, std::is_class<U>::value);
    typedef int A[10];
    BOOST_REQUIRE_EQUAL(xxx, std::is_class<A>::value);
}

BOOST_AUTO_TEST_CASE(is_function)
{
    struct S {};
    S s1();
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<decltype(s1)>::value);
    S s2{};
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<decltype(s2)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<void()>::value);
    typedef void p();
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<p>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<p *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_function<std::function<void()>>::value);
}

BOOST_AUTO_TEST_CASE(is_pointer)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<void>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<void *>::value);
    int i;
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<decltype(&i)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<decltype('&')>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<decltype("Hello, world!")>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_pointer<decltype("Hello, world!" + 1)>::value);
}

BOOST_AUTO_TEST_CASE(is_lvalue_reference)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_lvalue_reference<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_lvalue_reference<int &>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_lvalue_reference<int &&>::value);
    int i;
    BOOST_REQUIRE_EQUAL(xxx, std::is_lvalue_reference<decltype(&i)>::value);
}

BOOST_AUTO_TEST_CASE(is_rvalue_reference)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_rvalue_reference<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_rvalue_reference<int &>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_rvalue_reference<int &&>::value);
    int i;
    BOOST_REQUIRE_EQUAL(xxx, std::is_rvalue_reference<decltype(&i)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_rvalue_reference<decltype(std::move(i))>::value);
}

BOOST_AUTO_TEST_CASE(is_member_object_pointer)
{
    struct S { int i; };
    S s;
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<decltype(&s)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<decltype(&S::i)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<int(S::*)>::value);
    union U { int i; char c; };
    U u;
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<decltype(&u)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<decltype(&U::i)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_object_pointer<int(U::*)>::value);
}

BOOST_AUTO_TEST_CASE(is_member_function_pointer)
{
    struct S { char c; void i() {} };
    S s;
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_function_pointer<decltype(&s)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_function_pointer<decltype(&S::i)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_function_pointer<decltype(&S::c)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_member_function_pointer<void(S::*)()>::value);
}

BOOST_AUTO_TEST_CASE(is_arithmetic)
{
    BOOST_REQUIRE_EQUAL(false, std::is_arithmetic<void>::value);
    BOOST_REQUIRE_EQUAL(false, std::is_arithmetic<std::nullptr_t>::value);
    BOOST_REQUIRE_EQUAL(std::is_integral<XXX>::value, std::is_arithmetic<bool>::value);
    BOOST_REQUIRE_EQUAL(std::is_floating_point<XXX>::value, std::is_arithmetic<float>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_arithmetic<char>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_arithmetic<char16_t>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_arithmetic<char32_t>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_arithmetic<wchar_t>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_arithmetic<unsigned char>::value);
    BOOST_REQUIRE_EQUAL(true, std::is_arithmetic<std::vector<XXX>::value_type>::value);
}

BOOST_AUTO_TEST_CASE(is_fundamental)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<void>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<std::nullptr_t>::value);
    BOOST_REQUIRE_EQUAL(std::is_arithmetic<XXX>::value, std::is_fundamental<bool>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<char>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<unsigned char>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<double>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<std::string>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<decltype("Hello, world!")>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<decltype("Hello, world!" + 1)>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<std::vector<int *>>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<std::vector<int> *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_fundamental<std::vector<int>::value_type>::value);
}

BOOST_AUTO_TEST_CASE(is_const)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<const int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<int const *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<const int *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<int *const>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<int const *const>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_const<int const &>::value);
}

BOOST_AUTO_TEST_CASE(is_volatile)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<volatile int>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<int volatile *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<volatile int *>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<int *volatile>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<int volatile *volatile>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_volatile<int volatile &>::value);
}

BOOST_AUTO_TEST_CASE(is_trivial)
{
    BOOST_REQUIRE_EQUAL(xxx, std::is_trivial<int>::value);
    class Empty {};
    BOOST_REQUIRE_EQUAL(xxx, std::is_trivial<Empty>::value);
    BOOST_REQUIRE_EQUAL(xxx, std::is_trivial<Empty[10]>::value);
    class CustomConstructor
    {
    public:
        CustomConstructor(int i) : i_(i) {}
    private:
        int &i_;
    };
    BOOST_REQUIRE_EQUAL(xxx, std::is_trivial<CustomConstructor>::value);
}
