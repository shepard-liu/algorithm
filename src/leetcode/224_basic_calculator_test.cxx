#include "224_basic_calculator.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, int> TestCase;

void test_basic_calculator(TestCase& c) {
    auto [str, ans] = c;
    auto myAns = calculate(str);
    std::cout << "expr: " << str << std::endl;
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, basic_calculator) {
    std::vector<TestCase> cases{{"(4-(5+3))*4  / 2", -8},
                                {"5*3-4+2", 13},
                                {"1 + 1", 2},
                                {" 2-1 + 2 ", 3},
                                {"(1+(4+5+2)-3)+(6+8)", 23}};

    for (TestCase& c : cases) {
        test_basic_calculator(c);
    }
}
