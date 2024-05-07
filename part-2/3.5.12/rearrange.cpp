#include <iostream>
#include <vector> 
#include <algorithm>

template<class FwdIt>
FwdIt rearrange_nnz_even_odd(FwdIt p, FwdIt q) {
    return std::partition(std::partition(p, q, [](auto const & x) { // typename FwdIt::value_type 
        return x != 0 && x % 2 == 0; 
    }), q, [](auto const & x) {
        return x != 0; 
    });
}

int main() {
    std::vector<int> v = {0, 1, 2, 0, 3, 4, 5, 6, 7, 0, 8, 9, 10, 0};
    rearrange_nnz_even_odd(v.begin(), v.end());
    v.erase(rearrange_nnz_even_odd(v.begin(), v.end()), v.end());
    std::cout << "{ ";
    for (int e : v) 
        std::cout << e << ' ';
    std::cout << "}\n";
}