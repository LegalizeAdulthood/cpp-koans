#pragma once

#include <array>
#include <functional>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

struct XXX
{
    operator bool() { throw std::runtime_error("Oops"); }
	operator int() { throw std::runtime_error("Oops"); }
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
