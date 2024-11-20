#include "bezout_coeffs.hpp"

#include "gtest/gtest.h"

void test_bezout_coeffs(int64_t m, int64_t n, int64_t s, int64_t t) {
    auto [ans_s, ans_t] = bezout_coeffs(m, n);
    EXPECT_TRUE((ans_s == s || s == 0) && (ans_t == t || t == 0))
        << "bezout_coeffs(" << m << ", " << n << ") expected: (" << s << ", "
        << t << "), got (" << ans_s << ", " << ans_t << ")";
}

TEST(number_theory, bezout_coeffs) {
    test_bezout_coeffs(252, 198, 4, -5);
    test_bezout_coeffs(198, 252, -5, 4);
    test_bezout_coeffs(-198, 252, 5, 4);
    test_bezout_coeffs(-198, -252, 5, -4);
    test_bezout_coeffs(54, 18, 0, 1);
    test_bezout_coeffs(0, 0, 0, 0);
    test_bezout_coeffs(5, 0, 1, 0);    // t can be any number
    test_bezout_coeffs(0, 5, 0, 1);    // s can be any number
    test_bezout_coeffs(-5, 0, -1, 0);  // t can be any number
}