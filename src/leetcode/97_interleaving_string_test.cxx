#include "97_interleaving_string.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef tuple<string, string, string, bool> TestCase;

void test_interleaving_string(TestCase& c) {
    auto [s1, s2, s3, ans] = c;
    auto myAns = isInterleave(s1, s2, s3);
    EXPECT_EQ(ans, myAns) << "s1: " << s1 << "; s2: " << s2 << "; s3: " << s3;
}

TEST(leetcode, interleaving_string) {
    TestCase c1{"aabcc", "dbbca", "aadbbbaccc", false};
    TestCase c2{"aabcc", "dbbca", "aadbbcbcac", true};
    std::vector<TestCase> cases{c1, c2};

    for (TestCase& c : cases) {
        test_interleaving_string(c);
    }
}
