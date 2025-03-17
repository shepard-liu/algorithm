#include "392_is_subsequence.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<string, string, bool> TestCase;

void test_is_subsequence(TestCase& c) {
    auto [s, t, ans] = c;
    auto myAns = isSubsequence(s, t);
    EXPECT_EQ(ans, myAns) << s << ", " << t;
}

TEST(leetcode, is_subsequence) {
    std::vector<TestCase> cases{{"abc", "ahbgdc", true},
                                {"axc", "ahbgdc", false},
                                {"", "", true},
                                {"", "abc", true}};

    for (TestCase& c : cases) {
        test_is_subsequence(c);
    }
}
