#include "202_happy_number.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<int, bool> TestCase;

void test_happy_number(TestCase& c) {
    auto [n, ans] = c;
    auto myAns = isHappy(n);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, happy_number) {
    std::vector<TestCase> cases{{19, true}, {2, false}};

    for (TestCase& c : cases) {
        test_happy_number(c);
    }
}
