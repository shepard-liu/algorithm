
#include "discrete_logarithm.hpp"

#include "gtest/gtest.h"
#include "modular_exponentiation.hpp"

void test_discrete_logarithm(uint64_t a, uint64_t r, uint64_t p,
                             bool exist = true) {
    uint64_t ans = discrete_logarithm(a, r, p);
    if (!exist) {
        EXPECT_EQ(ans, 0) << "0 is expected because base " << r << " log " << a
                          << " modular " << p << " does not exist.";
        return;
    }

    EXPECT_EQ(modular_exponentiation(r, ans, p), a)
        << "Expected " << r << "^" << ans << " = " << a;
}

TEST(number_theory, discrete_logarithm) {
    std::vector<std::pair<uint64_t, uint64_t>> root_prime_pairs{
        {2, 3},  {2, 5},  {3, 7},  {2, 11}, {2, 13}, {3, 17}, {2, 19},
        {5, 23}, {2, 29}, {3, 31}, {2, 37}, {6, 41}, {3, 43}, {5, 47},
        {2, 53}, {2, 59}, {2, 61}, {2, 67}, {7, 71}, {5, 73}, {3, 79},
        {2, 83}, {3, 89}, {5, 97}, {2, 101}};

    for (const auto& [pr, p] : root_prime_pairs) {
        for (uint64_t i = 1; i < p; ++i) {
            test_discrete_logarithm(i, pr, p, true);
        }
        test_discrete_logarithm(0, pr, p, false);
    }
}