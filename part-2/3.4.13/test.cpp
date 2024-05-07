#include <gtest/gtest.h>
#include <vector>
#include "VectorList.hpp"

TEST(VectorList, EmptyContainer) {
    VectorList<int> x;
    ASSERT_EQ(x.begin(), x.end());
    for (auto it = x.begin(); it != x.end(); ++it)
        FAIL() << "empty container";
    ASSERT_EQ(x.rbegin(), x.rend());
    for (auto it = x.rbegin(); it != x.rend(); ++it)
        FAIL() << "empty container";
}

TEST(VectorList, ForwardIteration) {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5};
    VectorList<int> x;
    for (auto const & v : {v1, v2}) 
        x.append(v.begin(), v.end());
    int i = 1;
    for (auto it = x.begin(); it != x.end(); ++it, ++i) {
        EXPECT_EQ(*it, i);
        ASSERT_LE(i, 5);
    }
    EXPECT_EQ(i, 6);
}

TEST(VectorList, ReverseIteration) {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5};
    VectorList<int> x;
    for (auto const & v : {v1, v2}) 
        x.append(v.begin(), v.end());
    int i = 5;
    for (auto it = x.rbegin(); it != x.rend(); ++it, --i) {
        EXPECT_EQ(*it, i);
        ASSERT_GE(i, 1);
    }
    EXPECT_EQ(i, 0);
}