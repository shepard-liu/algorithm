#include "22_generate_parentheses.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

void test_generate_parentheses(TestCase& c) {
    auto n = c;
    auto myAns = generateParenthesis(n);
    std::cout << myAns << std::endl;
}

TEST(leetcode, generate_parentheses) {
    std::vector<TestCase> cases{3, 5, 4, 6};

    for (TestCase& c : cases) {
        test_generate_parentheses(c);
    }
}
