#include "77_combinations.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<int, int> TestCase;

void test_combinations(TestCase& c) {
    auto [n, r] = c;
    int ans = binomial(n, r);
    auto myAns = combine(n, r);
    std::cout << "myAns" << myAns << std::endl;
    EXPECT_EQ(ans, myAns.size());
}

TEST(leetcode, combinations) {
    std::vector<TestCase> cases{{5, 3}, {6, 4}, {7, 3}, {8, 4}};

    for (TestCase& c : cases) {
        test_combinations(c);
    }

    combine(6, 3);
}
