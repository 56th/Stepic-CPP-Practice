#include "IntList.hpp"

using primes = IntList<2, 3, 5, 7, 11, 13>;
static_assert(primes::Head == 2);
static_assert(primes::Tail::Head == 3);
static_assert(primes::Tail::Tail::Head == 5);
static_assert(primes::Tail::Tail::Tail::Head == 7);
static_assert(primes::Tail::Tail::Tail::Tail::Head == 11);
static_assert(primes::Tail::Tail::Tail::Tail::Tail::Head == 13);