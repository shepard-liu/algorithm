#include "52_n_queens_ii.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<int, int> TestCase;

void test_n_queens_ii(TestCase& c) {
    auto [n, ans] = c;
    auto myAns = totalNQueens(n);
    EXPECT_EQ(myAns, ans) << "n: " << n;
}

TEST(leetcode, n_queens_ii) {
    std::vector<TestCase> cases{{4, 2},  {5, 10}, {6, 4},
                                {7, 40}, {8, 92}, {9, 352}};

    for (TestCase& c : cases) {
        test_n_queens_ii(c);
    }
}
