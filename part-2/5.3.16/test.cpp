#include <gtest/gtest.h>
#include "Quantity.hpp"

TEST(Quantity, VelocityQ) {
    LengthQ l(30000);      
    TimeQ t(10 * 60);    
    auto v = l / t;
    static_assert(std::is_same<VelocityQ, decltype(v)>::value);
    ASSERT_EQ(v.value(), l.value() / t.value());
    ASSERT_EQ((v / 2).value(), v.value() / 2);                    
}

TEST(Quantity, ForceQ) {
    AccelQ a(9.8);
    MassQ m(80);         
    auto f = m * a;
    static_assert(std::is_same<ForceQ, decltype(f)>::value);
    ASSERT_EQ(f.value(), m.value() * a.value());       
    ASSERT_EQ((.9 * f).value(), .9 * f.value());   
}