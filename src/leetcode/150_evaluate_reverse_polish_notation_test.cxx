#include "150_evaluate_reverse_polish_notation.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<string>, int> TestCase;

void test_evaluate_reverse_polish_notation(TestCase& c) {
    auto [tokens, ans] = c;
    auto myAns = evalRPN(tokens);
    std::cout << tokens << std::endl;
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, evaluate_reverse_polish_notation) {
    std::vector<TestCase> cases{
        {{"2", "1", "+", "3", "*"}, 9},
        {{"4", "13", "5", "/", "+"}, 6},
        {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"},
         22}};

    for (TestCase& c : cases) {
        test_evaluate_reverse_polish_notation(c);
    }
}
