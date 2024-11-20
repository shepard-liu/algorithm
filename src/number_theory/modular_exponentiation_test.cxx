#include "modular_exponentiation.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <limits>
#include <random>

void test_modular_exponentiation(uint64_t b, uint64_t n, uint64_t m,
                                 uint64_t expected) {
    EXPECT_EQ(modular_exponentiation(b, n, m), expected)
        << "Failed on: (" << b << ", " << n << ", " << m << ").";
}

TEST(number_theory, modular_exponentiation) {
    test_modular_exponentiation(3, 2, 11, 9);
    test_modular_exponentiation(3, 644, 645, 36);
    test_modular_exponentiation(7, 644, 645, 436);
    test_modular_exponentiation(11, 644, 645, 1);
    test_modular_exponentiation(3, 2003, 99, 27);
    test_modular_exponentiation(123, 1001, 101, 22);

    std::mt19937_64 gen;
    std::uniform_int_distribution<> dist(1, 1e5);

    for (size_t i = 0; i < 1e5; i++) {
        modular_exponentiation(dist(gen), dist(gen), dist(gen));
    }
}