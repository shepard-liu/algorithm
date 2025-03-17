#include "433_minimum_genetic_mutation.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<string, string, vector<string>, int> TestCase;

void test_minimum_genetic_mutation(TestCase& c) {
    auto [s, e, b, ans] = c;

    auto myAns = minMutation(s, e, b);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, minimum_genetic_mutation) {
    std::vector<TestCase> cases{
        {"AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3}};

    for (TestCase& c : cases) {
        test_minimum_genetic_mutation(c);
    }
}
