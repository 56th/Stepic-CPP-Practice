#include <gtest/gtest.h>
#include "apply.hpp"

TEST(apply, ThreeArgs) {
    auto f = [](int x, double y, double z) { return x + y + z; };
    auto t = std::make_tuple(30, 5.0, 1.6);
    ASSERT_EQ(apply(f, t), f(std::get<0>(t), std::get<1>(t), std::get<2>(t)));
}

TEST(apply, MutableArg) {
    auto f = [](int& x) { x *= 2; };
    auto t = std::make_tuple(3);
    apply(f, t);
    ASSERT_EQ(std::get<0>(t), 6);
}