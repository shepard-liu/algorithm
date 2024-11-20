#include "gcd.hpp"

#include <gtest/gtest.h>

void test_gcd(int64_t m, int64_t n, int64_t expected) {
    int64_t ans = gcd(m, n);
    EXPECT_EQ(ans, expected) << "gcd(" << m << ", " << n << ") should be "
                             << expected << "got " << ans;
}

TEST(number_theory, gcd) {
    test_gcd(91, 287, 7);
    test_gcd(662, 414, 2);
    test_gcd(252, 198, 18);
    test_gcd(0, 0, 0);
    test_gcd(0, 5, 5);
    test_gcd(5, 0, 5);
    test_gcd(-5, 0, 5);
    test_gcd(8, 1, 1);
    test_gcd(1, 8, 1);
    test_gcd(1, -8, 1);
    test_gcd(1, -8, 1);
}