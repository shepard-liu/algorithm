#include "135_candy.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, int> TestCase;

void test_candy(TestCase& c) {
    int ans = candy(c.first);
    std::cout << c.first << std::endl;
    EXPECT_EQ(ans, c.second);
}

TEST(leetcode, candy) {
    std::vector<TestCase> cases{
        {{1, 3, 2, 2, 1}, 7},
        {{1, 0, 2}, 5},
        {{1, 2, 2}, 4},
    };

    for (TestCase& c : cases) {
        test_candy(c);
    }
}
