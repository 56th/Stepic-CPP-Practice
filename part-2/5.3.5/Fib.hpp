template<unsigned N> // note: can also be achieved w constexpr
struct Fib {
    static unsigned const value = Fib<N - 2>::value + Fib<N - 1>::value;
};

// specializations

template<>
struct Fib<0> {
    static unsigned const value = 0;
};

template<>
struct Fib<1> {
    static unsigned const value = 1;
};