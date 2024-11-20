

#include "prng.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <exception>
#include <iostream>
#include <numeric>
#include <vector>

void test_linear_congruential_generator(uint64_t m, uint64_t a, uint64_t c,
                                        uint64_t x0) {
    auto ans = linear_congruential_generator(m, a, c, x0);

    EXPECT_TRUE(ans.size() == m)
        << "Invalid sequence size: " << ans.size() << ", expected " << m;

    std::vector<bool> bucket(m, false);

    for (auto n : ans) {
        bucket[n] = true;
        std::cout << n << " ";
    }
    std::cout << std::endl;

    bool has_all_numbers =
        std::accumulate(bucket.begin(), bucket.end(), true,
                        [](bool acc, bool cur) { return acc && cur; });

    EXPECT_TRUE(has_all_numbers) << "Not all numbers from 0~" << m - 1
                                 << " found in the generated sequence";
}

TEST(number_theory, linear_congruential_generator) {
    test_linear_congruential_generator(9, 7, 4, 3);
}

void test_power_congruential_generator(uint64_t p, uint64_t d, uint64_t x0) {
    auto ans = power_congruential_generator(p, d, x0);

    for (auto n : ans) {
        std::cout << n << " ";
    }

    std::cout << std::endl;
}

TEST(number_theory, power_congruential_generator) {
    test_power_congruential_generator(7, 3, 2);
    test_power_congruential_generator(11, 2, 3);
}