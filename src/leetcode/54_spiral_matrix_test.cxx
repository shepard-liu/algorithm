#include "54_spiral_matrix.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<vector<int>>, vector<int>> TestCase;

void test_spiral_matrix(TestCase& c) {
    auto [matrix, ans] = c;
    auto myAns = spiralOrder(matrix);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, spiral_matrix) {
    std::vector<TestCase> cases{
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
         {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}}};

    for (TestCase& c : cases) {
        test_spiral_matrix(c);
    }
}
