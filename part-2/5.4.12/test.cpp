#include <gtest/gtest.h>
#include "get_size.hpp"

TEST(get_size, StdString) {
    std::string s("Hello");
    ASSERT_EQ(get_size(s), 5);                    
}

TEST(get_size, MemberVar) {
    struct Struct { 
        size_t size = 0;  
    };
    ASSERT_EQ(get_size(Struct{10}), 10);
}