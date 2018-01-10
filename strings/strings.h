#pragma once

#include <iterator>
#include <string>
#include <type_traits>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

struct XXX
{
    operator bool() const { throw std::runtime_error{"Oops"}; }
    operator int() const { throw std::runtime_error{"Oops"}; }
    operator std::string::size_type() const { throw std::runtime_error{"Oops"}; }
    operator std::string::iterator() const { throw std::runtime_error{"Oops"}; }
    operator char() const { throw std::runtime_error{"Oops"}; }
};

XXX xxx;

inline std::ostream &operator<<(std::ostream &stream, XXX const &)
{
    return stream << "xxx";
}

template <typename T>
inline bool operator==(XXX const &lhs, T const &rhs)
{
    return false;
}

#pragma warning(disable : 4101) // unreferenced local variable
#pragma warning(disable : 4930) // prototyped function not called
