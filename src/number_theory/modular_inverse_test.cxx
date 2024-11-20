#include "modular_inverse.hpp"

#include "gcd.hpp"
#include "gtest/gtest.h"

void test_modular_inverse(int64_t a, int64_t m) {
    int g = gcd(a, m);
    auto ans = modular_inverse(a, m);
    if (g != 1) {
        EXPECT_EQ(ans, 0)
            << "modular_inverse(" << a << ", " << m
            << ") should return 0 when the inverse does not exist";
    } else {
        EXPECT_TRUE((ans * a - 1) % m == 0)
            << "modular_inverse(" << a << ", " << m << ") return wrong answer";
    }
}

TEST(number_theory, bezout_coeffs) {
    test_modular_inverse(3, 7);
    test_modular_inverse(101, 4620);
    test_modular_inverse(101, -4620);
    test_modular_inverse(-101, 4620);
    test_modular_inverse(0, 5);  // does not exist
}