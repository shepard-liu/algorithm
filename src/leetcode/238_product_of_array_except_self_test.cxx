#include "238_product_of_array_except_self.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <functional>
#include <numeric>
#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_product_of_array_except_self(TestCase& c) {
    std::vector<int> expect(c.size(), 1);
    int prod = std::accumulate(c.begin(), c.end(), 1, std::multiplies<int>());
    for (size_t i = 0; i < c.size(); ++i) {
        expect[i] = prod / c[i];
    }

    auto ans = productExceptSelf(c);
    EXPECT_EQ(ans, expect);
}

TEST(leetcode, product_of_array_except_self) {
    std::vector<TestCase> cases{
        {1, 2, 3, 4}, {-1, 1, 0, -3, 3}, {5, 6, 1, 2, 6}};

    for (TestCase& c : cases) {
        test_product_of_array_except_self(c);
    }
}
