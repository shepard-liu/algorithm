#include "772_construct_quad_tree.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef vector<vector<int>> TestCase;

void test_construct_quad_tree(TestCase& c) {
    auto grid = c;
    auto myAns = construct(grid);
}

TEST(leetcode, construct_quad_tree) {
    std::vector<TestCase> cases{{{0, 1}, {1, 0}},
                                {{1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0, 0, 0, 0}}};

    for (TestCase& c : cases) {
        test_construct_quad_tree(c);
    }
}
