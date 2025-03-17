

#include "miller_test.hpp"

#include <vector>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

void test_miller_test(uint64_t n, bool v) {
    bool ans = miller_test(n);
    EXPECT_TRUE(ans == v) << "miller_test(" << n << ") got "
                          << (ans ? "true" : "false") << ", expect "
                          << (v ? "true" : "false");
}

TEST(number_theory, miller_test) {
    // primes
    for (uint64_t n : primes) {
        test_miller_test(n, true);
    }

    std::vector<uint64_t> composites{341,  561,  645,  759, 861,
                                     1105, 1387, 1729, 1891};
    for (uint64_t n : composites) {
        test_miller_test(n, false);
    }

    std::vector<uint64_t> big_primes{8191, 131071, 524287, 6700417};
    for (uint64_t n : big_primes) {
        test_miller_test(n, true);
    }
}