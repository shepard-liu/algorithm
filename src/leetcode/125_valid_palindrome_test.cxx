#include "125_valid_palindrome.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, bool> TestCase;

void test_valid_palindrome(TestCase& c) {
    auto ans = isPalindrome(c.first);
    EXPECT_EQ(c.second, ans) << c.first;
}

TEST(leetcode, valid_palindrome) {
    std::vector<TestCase> cases{{"A man, a plan, a canal: Panama", true},
                                {"race a car", false},
                                {" ", true},
                                {"0P", false}};

    for (TestCase& c : cases) {
        test_valid_palindrome(c);
    }
}
