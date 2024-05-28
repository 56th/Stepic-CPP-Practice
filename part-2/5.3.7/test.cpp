#include "IntList.hpp"

using primes = IntList<2, 3, 5, 7, 11, 13>;

static_assert(primes::Head == 2);
static_assert(primes::Tail::Head == 3);
static_assert(primes::Tail::Tail::Head == 5);
static_assert(primes::Tail::Tail::Tail::Head == 7);
static_assert(primes::Tail::Tail::Tail::Tail::Head == 11);
static_assert(primes::Tail::Tail::Tail::Tail::Tail::Head == 13);

static_assert(primes::Length == 6);
static_assert(primes::Tail::Length == 5);
static_assert(primes::Tail::Tail::Length == 4);
static_assert(primes::Tail::Tail::Tail::Length == 3);
static_assert(primes::Tail::Tail::Tail::Tail::Length == 2);
static_assert(primes::Tail::Tail::Tail::Tail::Tail::Length == 1);
static_assert(primes::Tail::Tail::Tail::Tail::Tail::Tail::Length == 0);

static_assert(Length<primes>::value == 6);
static_assert(Length<primes::Tail>::value == 5);
static_assert(Length<primes::Tail::Tail>::value == 4);
static_assert(Length<primes::Tail::Tail::Tail>::value == 3);
static_assert(Length<primes::Tail::Tail::Tail::Tail>::value == 2);
static_assert(Length<primes::Tail::Tail::Tail::Tail::Tail>::value == 1);
static_assert(Length<primes::Tail::Tail::Tail::Tail::Tail::Tail>::value == 0);