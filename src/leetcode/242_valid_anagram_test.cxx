#include "242_valid_anagram.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<string, string, bool> TestCase;

void test_valid_anagram(TestCase& c) {
    auto [s, t, ans] = c;
    auto myAns = isAnagram(s, t);
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, valid_anagram) {
    std::vector<TestCase> cases{{"anagram", "nagaram", true},
                                {"aabbc", "bbaad", false},
                                {"rat", "car", false}};

    for (TestCase& c : cases) {
        test_valid_anagram(c);
    }
}
