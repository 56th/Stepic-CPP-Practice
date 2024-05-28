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

template<typename IL> // alternative to IntList<...>::Length
struct Length {
    static int const value = 1 + Length<typename IL::Tail>::value;
};

template<>
struct Length<IntList<>> {
    static int const value = 0;
};