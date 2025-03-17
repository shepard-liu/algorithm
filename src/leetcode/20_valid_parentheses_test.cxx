#include "20_valid_parentheses.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, bool> TestCase;

void test_valid_parentheses(TestCase& c) {
    auto [str, ans] = c;
    auto myAns = isValid(str);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, valid_parentheses) {
    std::vector<TestCase> cases{
        {"()", true}, {"()[]{}", true}, {"(]", false}, {"([])", true}};

    for (TestCase& c : cases) {
        test_valid_parentheses(c);
    }
}
