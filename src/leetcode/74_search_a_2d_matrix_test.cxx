#include "74_search_a_2d_matrix.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef vector<vector<int>> TestCase;

void test_search_a_2d_matrix(TestCase& c) {
    auto matrix = c;
    auto myAns = searchMatrix(matrix, 0);
    EXPECT_EQ(myAns, false);
}

TEST(leetcode, search_a_2d_matrix) {
    TestCase c1{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    TestCase c2{{1, 1}};
    std::vector<TestCase> cases{c1, c2};

    for (TestCase& c : cases) {
        test_search_a_2d_matrix(c);
    }
}
