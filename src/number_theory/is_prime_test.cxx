#include "is_prime.hpp"

#include <vector>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

void test_is_prime(uint64_t n, bool prime) {
    bool ans = is_prime(n);
    EXPECT_TRUE(ans == prime)
        << "is_prime(" << n << ") got " << (ans ? "true" : "false")
        << ", expect " << (prime ? "true" : "false");
}

TEST(number_theory, is_prime) {
    std::vector<bool> prime_indicator(100, false);
    for (uint64_t n : primes) {
        prime_indicator[n] = true;
    }

    for (uint64_t n = 0; n < 100; n++) {
        test_is_prime(n, prime_indicator[n]);
    }

    std::vector<uint64_t> big_primes{8191, 131071, 524287, 6700417};
    for (uint64_t n : big_primes) {
        test_is_prime(n, true);
    }
}