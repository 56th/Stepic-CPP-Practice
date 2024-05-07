#include <algorithm>
#include <vector>

template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    using T = typename std::iterator_traits<Iterator>::value_type; // Iterator::value_type will not work for raw pointers
    std::vector<T> v(p, q); // copy first to handle const cases
    std::sort(v.begin(), v.end());
    size_t n = 0;
    do {
        n += std::adjacent_find(v.begin(), v.end()) == v.end();
    } while (std::next_permutation(v.begin(), v.end()));
    return n;
}