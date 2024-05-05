#include <iostream>
#include <vector> 

template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n) {
    for (size_t i = 0; i < n; ++i)
        if (++p == q)
            break;
    if (p != q)
        for (auto it = p; ++it != q;) 
           *p++ = std::move(*it);
    return p;
}

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    v.erase(remove_nth(v.begin(), v.end(), 5), v.end());
    std::cout << "{ ";
    for (int e : v) 
        std::cout << e << ' ';
    std::cout << "}\n";
}