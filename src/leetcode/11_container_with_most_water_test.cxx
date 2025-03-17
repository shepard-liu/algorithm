#include "11_container_with_most_water.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_container_with_most_water(TestCase& c) {
    int max = 0;
    for (size_t i = 0; i < c.size(); ++i) {
        for (size_t j = i + 1; j < c.size(); ++j) {
            int area = std::min(c[i], c[j]) * (j - i);
            if (area > max) {
                max = area;
            }
        }
    }
    std::cout << c << std::endl;
    EXPECT_EQ(max, maxArea(c));
}

TEST(leetcode, container_with_most_water) {
    std::vector<TestCase> cases{{1, 8, 1, 1,  1, 1,  100, 100, 100, 1, 1,
                                 1, 1, 1, 10, 1, 24, 5,   64,  12,  12},
                                {1, 8, 6, 2, 5, 4, 8, 3, 7},
                                {1, 1}};

    for (TestCase& c : cases) {
        test_container_with_most_water(c);
    }

    for (size_t seed = 0; seed < 1000; ++seed) {
        auto c = random_int_array(seed + 1, seed, 0, seed);
        test_container_with_most_water(c);
    }
}
