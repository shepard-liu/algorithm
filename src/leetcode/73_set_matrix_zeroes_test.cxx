#include "73_set_matrix_zeroes.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<vector<int>>, vector<vector<int>>> TestCase;

void test_set_matrix_zeroes(TestCase& c) {
    auto [i, ans] = c;
    auto myAns = i;
    setZeroes(myAns);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, set_matrix_zeroes) {
    std::vector<TestCase> cases{
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
        {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
         {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}}};

    for (TestCase& c : cases) {
        test_set_matrix_zeroes(c);
    }
}
