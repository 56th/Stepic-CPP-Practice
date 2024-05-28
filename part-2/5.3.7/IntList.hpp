template<int... Vals>
struct IntList { // empty by default
};

template<int N, int... Vals>
struct IntList<N, Vals...> { // specialization for the length >= 1 
    static int const Head = N;
    using Tail = IntList<Vals...>;
};