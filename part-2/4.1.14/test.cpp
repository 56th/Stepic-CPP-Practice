#include <limits>
#include <gtest/gtest.h>
#include <string>
#include "from_string.hpp"

TEST(from_string, ValidIntCasts) {
    EXPECT_EQ(from_string<int>("0"), 0);
    EXPECT_EQ(from_string<int>("-0"), 0);
    EXPECT_EQ(from_string<int>("1"), 1);
    EXPECT_EQ(from_string<int>("-1"), -1);
    auto m = std::numeric_limits<int>::max();
    EXPECT_EQ(from_string<int>(std::to_string(m)), m);
    EXPECT_EQ(from_string<int>(std::to_string(m + 1)), m + 1);
}

TEST(from_string, ValidCharCasts) {
    for (auto c = std::numeric_limits<char>::min(); c != std::numeric_limits<char>::max(); ++c)
        EXPECT_EQ(from_string<char>(std::string(1, c)), c);
}

TEST(from_string, ValidFPCasts) {
    EXPECT_EQ(from_string<float>("0"), 0.f);
    EXPECT_EQ(from_string<float>("0.2"), .2f);
    EXPECT_EQ(from_string<double>("0.2"), .2);
}

TEST(from_string, InvalidIntCasts) {
    EXPECT_THROW(from_string<int>("+"), bad_from_string);
    EXPECT_THROW(from_string<int>(" 0"), bad_from_string);
    EXPECT_THROW(from_string<int>("0 "), bad_from_string);
    EXPECT_THROW(from_string<int>("1.23"), bad_from_string);
    EXPECT_THROW(from_string<int>("-1.23"), bad_from_string);
}