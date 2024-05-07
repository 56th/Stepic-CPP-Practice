#include <gtest/gtest.h>
#include <vector>
#include "count_permutations.hpp"

TEST(count_permutations, EmptySequence) {
    std::vector<int> v;
    EXPECT_EQ(count_permutations(v.begin(), v.end()), 1);
}

TEST(count_permutations, SortedSequence) {
    int v[] = { 1, 2, 3, 4, 4 };
    EXPECT_EQ(count_permutations(std::begin(v), std::end(v)), 36);
}

TEST(count_permutations, UnsortedSequence) {
    int v[] = { 4, 2, 1, 3, 4 };
    EXPECT_EQ(count_permutations(std::begin(v), std::end(v)), 36);
}