#include "type_traits.h"
#include <type_traits>

// In each test, replace XXX with syntax that passes the test.

TEST_CASE("is_void")
{
    REQUIRE(std::is_void<XXX>::value);
    std::is_void<XXX> val;
    REQUIRE(static_cast<bool>(val));
}

TEST_CASE("is_integral")
{
    REQUIRE(std::is_integral<XXX>::value);
    REQUIRE(xxx == std::is_integral<int &>::value);
    REQUIRE(xxx == std::is_integral<int *>::value);
    REQUIRE(xxx == std::is_integral<decltype('!')>::value);
    REQUIRE(xxx == std::is_integral<decltype(false)>::value);
    REQUIRE(xxx == std::is_integral<decltype(666ULL)>::value);
    REQUIRE(xxx == std::is_integral<decltype(0.)>::value);
    REQUIRE(xxx == std::is_integral<decltype(0.f)>::value);
    REQUIRE(xxx == std::is_integral<decltype("Hello, world!")>::value);
    REQUIRE(xxx == std::is_integral<decltype(L'!')>::value);
    REQUIRE(xxx == std::is_integral<decltype(L"Hello, world!")>::value);
    REQUIRE(xxx == std::is_integral<decltype(R"(Hello, "world"!)")>::value);
    REQUIRE(xxx == std::is_integral<const int>::value);
}

TEST_CASE("is_floating_point")
{
    REQUIRE(xxx == std::is_floating_point<int>::value);
    REQUIRE(xxx == std::is_floating_point<float>::value);
    REQUIRE(xxx == std::is_floating_point<double>::value);
    REQUIRE(xxx == std::is_floating_point<long double>::value);
    REQUIRE(xxx == std::is_floating_point<decltype(0 + 1.)>::value);
    REQUIRE(xxx == std::is_floating_point<decltype(0. + 1)>::value);
    REQUIRE(xxx == std::is_floating_point<decltype(0 + 1)>::value);
}

TEST_CASE("is_array")
{
    REQUIRE(xxx == std::is_array<int>::value);
    typedef std::array<int, 10> std_array;
    REQUIRE(xxx == std::is_array<std_array>::value);
    REQUIRE(xxx == std::is_array<int *>::value);
    REQUIRE(xxx == std::is_array<int &>::value);
    REQUIRE(std::is_array<XXX>::value);
    REQUIRE(xxx == std::is_array<int *[10]>::value);
}

TEST_CASE("is_enum")
{
    REQUIRE(std::is_enum<XXX>::value);
}

TEST_CASE("is_union")
{
    REQUIRE(std::is_union<XXX>::value);
    struct S {};
    REQUIRE(xxx == std::is_union<S>::value);
}

TEST_CASE("is_class")
{
    REQUIRE(xxx == std::is_class<int>::value);
    struct S {};
    REQUIRE(xxx == std::is_class<S>::value);
    class C {};
    REQUIRE(xxx == std::is_class<C>::value);
    union U {};
    REQUIRE(xxx == std::is_class<U>::value);
    typedef int A[10];
    REQUIRE(xxx == std::is_class<A>::value);
}

TEST_CASE("is_function")
{
    struct S {};
    S s1();
    REQUIRE(xxx == std::is_function<decltype(s1)>::value);
    S s2{};
    REQUIRE(xxx == std::is_function<decltype(s2)>::value);
    REQUIRE(xxx == std::is_function<void()>::value);
    typedef void p();
    REQUIRE(xxx == std::is_function<p>::value);
    REQUIRE(xxx == std::is_function<p *>::value);
    REQUIRE(xxx == std::is_function<std::function<void()>>::value);
}

TEST_CASE("is_pointer")
{
    REQUIRE(xxx == std::is_pointer<void>::value);
    REQUIRE(xxx == std::is_pointer<void *>::value);
    int i;
    REQUIRE(xxx == std::is_pointer<decltype(&i)>::value);
    REQUIRE(xxx == std::is_pointer<decltype('&')>::value);
    REQUIRE(xxx == std::is_pointer<decltype("Hello, world!")>::value);
    REQUIRE(xxx == std::is_pointer<decltype("Hello, world!" + 1)>::value);
}

TEST_CASE("is_lvalue_reference")
{
    REQUIRE(xxx == std::is_lvalue_reference<int>::value);
    REQUIRE(xxx == std::is_lvalue_reference<int &>::value);
    REQUIRE(xxx == std::is_lvalue_reference<int &&>::value);
    int i;
    REQUIRE(xxx == std::is_lvalue_reference<decltype(&i)>::value);
}

TEST_CASE("is_rvalue_reference")
{
    REQUIRE(xxx == std::is_rvalue_reference<int>::value);
    REQUIRE(xxx == std::is_rvalue_reference<int &>::value);
    REQUIRE(xxx == std::is_rvalue_reference<int &&>::value);
    int i;
    REQUIRE(xxx == std::is_rvalue_reference<decltype(&i)>::value);
    REQUIRE(xxx == std::is_rvalue_reference<decltype(std::move(i))>::value);
}

TEST_CASE("is_member_object_pointer")
{
    struct S { int i; };
    S s;
    REQUIRE(xxx == std::is_member_object_pointer<decltype(&s)>::value);
    REQUIRE(xxx == std::is_member_object_pointer<decltype(&S::i)>::value);
    REQUIRE(xxx == std::is_member_object_pointer<int(S::*)>::value);
    union U { int i; char c; };
    U u;
    REQUIRE(xxx == std::is_member_object_pointer<decltype(&u)>::value);
    REQUIRE(xxx == std::is_member_object_pointer<decltype(&U::i)>::value);
    REQUIRE(xxx == std::is_member_object_pointer<int(U::*)>::value);
}

TEST_CASE("is_member_function_pointer")
{
    struct S { char c; void i() {} };
    S s;
    REQUIRE(xxx == std::is_member_function_pointer<decltype(&s)>::value);
    REQUIRE(xxx == std::is_member_function_pointer<decltype(&S::i)>::value);
    REQUIRE(xxx == std::is_member_function_pointer<decltype(&S::c)>::value);
    REQUIRE(xxx == std::is_member_function_pointer<void(S::*)()>::value);
}

TEST_CASE("is_arithmetic")
{
    REQUIRE(!std::is_arithmetic<void>::value);
    REQUIRE(!std::is_arithmetic<std::nullptr_t>::value);
    REQUIRE(std::is_integral<XXX>::value == std::is_arithmetic<bool>::value);
    REQUIRE(std::is_floating_point<XXX>::value == std::is_arithmetic<float>::value);
    REQUIRE(xxx == std::is_arithmetic<char>::value);
    REQUIRE(xxx == std::is_arithmetic<char16_t>::value);
    REQUIRE(xxx == std::is_arithmetic<char32_t>::value);
    REQUIRE(xxx == std::is_arithmetic<wchar_t>::value);
    REQUIRE(xxx == std::is_arithmetic<unsigned char>::value);
    REQUIRE(std::is_arithmetic<std::vector<XXX>::value_type>::value);
}

TEST_CASE("is_fundamental")
{
    REQUIRE(xxx == std::is_fundamental<void>::value);
    REQUIRE(xxx == std::is_fundamental<std::nullptr_t>::value);
    REQUIRE(std::is_arithmetic<XXX>::value == std::is_fundamental<bool>::value);
    REQUIRE(xxx == std::is_fundamental<char>::value);
    REQUIRE(xxx == std::is_fundamental<unsigned char>::value);
    REQUIRE(xxx == std::is_fundamental<int>::value);
    REQUIRE(xxx == std::is_fundamental<double>::value);
    REQUIRE(xxx == std::is_fundamental<std::string>::value);
    REQUIRE(xxx == std::is_fundamental<decltype("Hello, world!")>::value);
    REQUIRE(xxx == std::is_fundamental<decltype("Hello, world!" + 1)>::value);
    REQUIRE(xxx == std::is_fundamental<std::vector<int *>>::value);
    REQUIRE(xxx == std::is_fundamental<std::vector<int> *>::value);
    REQUIRE(xxx == std::is_fundamental<std::vector<int>::value_type>::value);
}

TEST_CASE("is_const")
{
    REQUIRE(xxx == std::is_const<int>::value);
    REQUIRE(xxx == std::is_const<const int>::value);
    REQUIRE(xxx == std::is_const<int const *>::value);
    REQUIRE(xxx == std::is_const<const int *>::value);
    REQUIRE(xxx == std::is_const<int *const>::value);
    REQUIRE(xxx == std::is_const<int const *const>::value);
    REQUIRE(xxx == std::is_const<int const &>::value);
}

TEST_CASE("is_volatile")
{
    REQUIRE(xxx == std::is_volatile<int>::value);
    REQUIRE(xxx == std::is_volatile<volatile int>::value);
    REQUIRE(xxx == std::is_volatile<int volatile *>::value);
    REQUIRE(xxx == std::is_volatile<volatile int *>::value);
    REQUIRE(xxx == std::is_volatile<int *volatile>::value);
    REQUIRE(xxx == std::is_volatile<int volatile *volatile>::value);
    REQUIRE(xxx == std::is_volatile<int volatile &>::value);
}

TEST_CASE("is_trivial")
{
    REQUIRE(xxx == std::is_trivial<int>::value);
    class Empty {};
    REQUIRE(xxx == std::is_trivial<Empty>::value);
    REQUIRE(xxx == std::is_trivial<Empty[10]>::value);
    class CustomConstructor
    {
    public:
        CustomConstructor(int i) : i_(i) {}
    private:
        int &i_;
    };
    REQUIRE(xxx == std::is_trivial<CustomConstructor>::value);
}
