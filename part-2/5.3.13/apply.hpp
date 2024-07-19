#include <tuple>
#include "part-2/5.3.7/IntList.hpp"

template<typename F, typename Tuple, int... Is>
auto apply(F&& f, Tuple&& tuple, IntList<Is...>) -> decltype(std::forward<F>(f)(std::get<Is>(std::forward<Tuple>(tuple))...)) {
    return std::forward<F>(f)(std::get<Is>(std::forward<Tuple>(tuple))...);
}

template<typename Tuple>
struct TupleIndexes {
    static typename Generate<std::tuple_size<typename std::remove_reference<Tuple>::type>::value>::type const value;
};

template<typename F, typename Tuple>
auto apply(F&& f, Tuple&& tuple) -> decltype(apply(std::forward<F>(f), std::forward<Tuple>(tuple), TupleIndexes<Tuple>::value)) {
    return apply(std::forward<F>(f), std::forward<Tuple>(tuple), TupleIndexes<Tuple>::value);
}