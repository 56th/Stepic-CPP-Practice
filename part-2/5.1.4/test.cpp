#include <list>
#include <gtest/gtest.h>
#include "map_reduce.hpp"

TEST(map_reduce, LinearExec) {
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sum = map_reduce(l.begin(), l.end(), [](int i) {
        return i;
    }, std::plus<int>());
    ASSERT_EQ(sum, 55);
    auto has_even = map_reduce(l.begin(), l.end(), [](int i) {
        return i % 2 == 0;
    }, std::logical_or<bool>());
    ASSERT_EQ(has_even, true);
    auto all_even = map_reduce(l.begin(), l.end(), [](int i) {
        return i % 2 == 0;
    }, std::logical_and<bool>());
    ASSERT_EQ(all_even, false);
}

TEST(map_reduce, AsyncExec) {
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t num_threads = 1; num_threads <= l.size(); ++num_threads) {
        auto sum = map_reduce(l.begin(), l.end(), [](int i) {
            return i;
        }, std::plus<int>());
        auto sum_async_future = map_reduce(l.begin(), l.end(), [](int i) {
            return i;
        }, std::plus<int>(), num_threads);
        auto sum_async_thread = map_reduce_thread(l.begin(), l.end(), [](int i) {
            return i;
        }, std::plus<int>(), num_threads);
        ASSERT_EQ(sum, sum_async_future) << "num threads: " << num_threads;
        ASSERT_EQ(sum, sum_async_thread) << "num threads: " << num_threads;
    }
}