#include "55_jump_game.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, bool> TestCase;

void test_jump_game(TestCase& c) {
    auto [nums, can] = c;
    ASSERT_EQ(canJump(nums), can);
}

TEST(leetcode, jump_game) {
    std::vector<TestCase> cases{{{2, 3, 1, 1, 4}, true},
                                {{3, 2, 1, 0, 4}, false}};

    for (TestCase& c : cases) {
        test_jump_game(c);
    }
}
