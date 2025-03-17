#include "452_minimum_number_of_arrows_to_burst_balloons.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<vector<int>>, int> TestCase;

void test_minimum_number_of_arrows_to_burst_balloons(TestCase& c) {
    auto [points, ans] = c;
    auto myAns = findMinArrowShots(points);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, minimum_number_of_arrows_to_burst_balloons) {
    std::vector<TestCase> cases{{{{10, 16}, {2, 8}, {1, 6}, {7, 12}}, 2},
                                {{{1, 2}, {3, 4}, {5, 6}, {7, 8}}, 4},
                                {{{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 2}};

    for (TestCase& c : cases) {
        test_minimum_number_of_arrows_to_burst_balloons(c);
    }
}
