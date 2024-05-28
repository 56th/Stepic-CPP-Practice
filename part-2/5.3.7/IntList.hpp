template<int... Vals>
struct IntList { // empty by default
};

template<int N, int... Vals>
struct IntList<N, Vals...> { // specialization for the length >= 1 
    static int const Head = N;
    using Tail = IntList<Vals...>;
};

template<typename IL>
struct Length {
    static int const value = 1 + Length<typename IL::Tail>::value;
};

template<>
struct Length<IntList<>> {
    static int const value = 0;
};