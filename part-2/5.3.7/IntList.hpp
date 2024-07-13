template<int... Vals>
struct IntList { // empty by default
    static int const Length = 0;
};

template<int N, int... Vals>
struct IntList<N, Vals...> { // specialization for the length >= 1 
    static int const Head = N;
    using Tail = IntList<Vals...>;
    static int const Length = 1 + sizeof...(Vals);
};

// Length meta function

template<typename IL> // alternative to IntList<...>::Length
struct Length {
    static int const value = 1 + Length<typename IL::Tail>::value;
};

template<>
struct Length<IntList<>> {
    static int const value = 0;
};

// IntCons meta function

template<int N, typename IL>
struct IntCons;

template<int N, int... Vals>
struct IntCons<N, IntList<Vals...>> {
    using type = IntList<N, Vals...>;
};

// Generate meta function

template<int N, int N0 = 0>
struct Generate {
    using type = typename IntCons<N0, typename Generate<N - 1, N0 + 1>::type>::type;
};

template<int N0>
struct Generate<0, N0> {
    using type = IntList<>;
};