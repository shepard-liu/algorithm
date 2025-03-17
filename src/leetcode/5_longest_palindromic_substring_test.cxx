#include "5_longest_palindromic_substring.hpp"

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<string, string> TestCase;

void test_longest_palindromic_substring(TestCase& c) {
    auto [s, ans] = c;
    auto myAns = longestPalindrome(s);

    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, longest_palindromic_substring) {
    std::vector<TestCase> cases{{"aaaa", "aaaa"}};

    for (TestCase& c : cases) {
        test_longest_palindromic_substring(c);
    }
}
