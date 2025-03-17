#include "64_minimum_path_sum.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<vector<int>>, int> TestCase;

void test_minimum_path_sum(TestCase& c) {
    auto [grid, ans] = c;
    auto myAns = minPathSum(grid);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, minimum_path_sum) {
    TestCase c1{{{1, 2, 3}, {4, 5, 6}}, 12};
    std::vector<TestCase> cases{c1};

    for (TestCase& c : cases) {
        test_minimum_path_sum(c);
    }
}
