#include "1250_longest_common_subsequence.hpp"

#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<string, string, int> TestCase;

void test_longest_common_subsequence(TestCase& c) {
    auto [s1, s2, ans] = c;
    auto myAns = longestCommonSubsequence(s1, s2);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, longest_common_subsequence) {
    std::vector<TestCase> cases{{"bsbininm", "jmjkbkjkv", 1}};

    for (TestCase& c : cases) {
        test_longest_common_subsequence(c);
    }
}
