#include "prime_factors.hpp"

#include <cmath>

#include "gtest/gtest.h"
#include "is_prime.hpp"

void test_prime_factors(int64_t n) {
    auto factors = prime_factors(n);

    if (n == 0 || std::abs(n) == 1) {
        EXPECT_TRUE(factors.size() == 0) << "0 or 1 has no prime factors";
        return;
    } else {
        EXPECT_TRUE(factors.size() >= 1)
            << n << " should have at least one prime factors";
    }

    uint64_t product = std::pow(factors[0].first, factors[0].second);
    EXPECT_TRUE(is_prime(factors[0].first))
        << "Non-prime in prime factor list: " << factors[0].first;

    for (size_t j = 0; j < factors[0].second; ++j) {
        std::cout << factors[0].first << " ";
    }
    for (size_t i = 1; i < factors.size(); i++) {
        auto last = factors[i - 1];
        auto cur = factors[i];
        EXPECT_TRUE(last.first <= cur.first)
            << "Prime factors must be in strictly descending order";
        EXPECT_TRUE(is_prime(cur.first))
            << "Non-prime in prime factor list:" << cur.first;
        product *= std::pow(cur.first, cur.second);

        for (size_t j = 0; j < cur.second; ++j) {
            std::cout << cur.first << " ";
        }
    }

    EXPECT_EQ(product, std::abs(n))
        << "Product of all prime integers is not equal to the number itself";
}

TEST(number_theory, prime_factors) {
    for (int i = 0; i < 1000; ++i) {
        test_prime_factors(i);
    }
}