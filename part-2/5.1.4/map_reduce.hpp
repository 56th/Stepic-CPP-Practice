#include <future>
#include <vector>

template<typename It, typename F1, typename F2>
auto map_reduce(It p, It q, F1 f1, F2 f2) -> decltype(f2(f1(*p), f1(*p))) {
    auto res = f1(*p);
    while (++p != q)
        res = f2(res, f1(*p));
    return res;
}

template<typename It, typename F1, typename F2>
auto map_reduce(It p, It q, F1 f1, F2 f2, size_t num_threads) -> decltype(f2(f1(*p), f1(*p))) {
    using Res = decltype(f2(f1(*p), f1(*p)));
    std::vector<std::future<Res>> res;
    res.reserve(num_threads);
    size_t elems_per_thread = std::distance(p, q) / num_threads;
    auto q_cur = p;
    while (p != q) {
        if (res.size() + 1 == num_threads)
            q_cur = q;
        else
            std::advance(q_cur, elems_per_thread);
        res.push_back(std::async(std::launch::async, [=]() {
            return map_reduce(p, q_cur, f1, f2);
        }));
        p = q_cur;
    }
    return map_reduce(res.begin(), res.end(), [](std::future<Res>& r) {
        return r.get();    
    }, f2);
}