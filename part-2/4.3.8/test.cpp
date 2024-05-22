#include <string>
#include <valarray>
#include "noexcept_do_math.hpp"

static_assert(noexcept(do_math<char>()));
static_assert(noexcept(do_math<int>()));
static_assert(noexcept(do_math<unsigned>()));
static_assert(noexcept(do_math<float>()));
static_assert(noexcept(do_math<double>()));
static_assert(!noexcept(do_math<std::string>()));
static_assert(!noexcept(do_math<std::valarray<int>>()));
