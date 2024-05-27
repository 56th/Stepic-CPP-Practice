#include "Fib.hpp"

static_assert(Fib<0>::value == 0);
static_assert(Fib<1>::value == 1);
static_assert(Fib<2>::value == 1);
static_assert(Fib<3>::value == 2);
static_assert(Fib<4>::value == 3);
static_assert(Fib<5>::value == 5);
static_assert(Fib<6>::value == 8);
static_assert(Fib<7>::value == 13);
static_assert(Fib<8>::value == 21);
static_assert(Fib<9>::value == 34);
static_assert(Fib<10>::value == 55);