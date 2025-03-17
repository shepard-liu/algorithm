#include "72_edit_distance.hpp"

#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<string, string, int> TestCase;

void test_edit_distance(TestCase& c) {
    auto [s1, s2, ans] = c;
    auto myAns = minDistance(s1, s2);
    EXPECT_EQ(myAns, ans) << "s1: " << s1 << "; s2: " << s2;
}

TEST(leetcode, edit_distance) {
    TestCase c1{"abcde", "ace", 2};
    TestCase c2{"abc", "abc", 0};
    TestCase c3{"execution", "intention", 5};
    TestCase c4{"horse", "ros", 3};
    std::vector<TestCase> cases{c1, c2, c3, c4};

    for (TestCase& c : cases) {
        test_edit_distance(c);
    }
}
