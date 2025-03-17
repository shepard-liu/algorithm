#include "300_longest_increasing_subsequence.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, int> TestCase;

void test_longest_increasing_subsequence(TestCase& c) {
    auto [arr, ans] = c;
    auto myAns = lengthOfLIS(arr);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, longest_increasing_subsequence) {
    std::vector<TestCase> cases{{{1, 3, 6, 7, 9, 4, 10, 5, 6}, 6}};

    for (TestCase& c : cases) {
        test_longest_increasing_subsequence(c);
    }
}
