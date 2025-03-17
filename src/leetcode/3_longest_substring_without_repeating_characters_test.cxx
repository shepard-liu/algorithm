#include "3_longest_substring_without_repeating_characters.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, int> TestCase;

void test_longest_substring_without_repeating_characters(TestCase& c) {
    auto [s, ans] = c;
    auto myAns = lengthOfLongestSubstring(c.first);
    EXPECT_EQ(ans, myAns) << c.first;
}

TEST(leetcode, longest_substring_without_repeating_characters) {
    std::vector<TestCase> cases{
        {"pwwkew", 3},
        {"abcabcbb", 3},
        {"bbbbb", 1},
    };

    for (TestCase& c : cases) {
        test_longest_substring_without_repeating_characters(c);
    }
}
