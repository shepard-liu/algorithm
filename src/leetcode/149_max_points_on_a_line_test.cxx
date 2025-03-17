#include "149_max_points_on_a_line.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<vector<int>>, int> TestCase;

void test_max_points_on_a_line(TestCase& c) {
    auto [points, ans] = c;
    auto myAns = maxPoints(points);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, max_points_on_a_line) {
    TestCase c1{{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4};
    TestCase c2{{{0, 0}, {2, 2}, {-1, -1}}, 3};
    std::vector<TestCase> cases{c2};

    for (TestCase& c : cases) {
        test_max_points_on_a_line(c);
    }
}
