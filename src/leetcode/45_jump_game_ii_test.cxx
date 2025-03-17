#include "45_jump_game_ii.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, int> TestCase;

void test_jump_game_ii(TestCase& c) { ASSERT_EQ(jump(c.first), c.second); }

TEST(leetcode, jump_game_ii) {
    std::vector<TestCase> cases{{{2, 3, 1, 1, 4}, 2}, {{2, 3, 0, 1, 4}, 2}};

    for (TestCase& c : cases) {
        test_jump_game_ii(c);
    }
}
