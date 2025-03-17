#include "289_game_of_life.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<vector<int>>, vector<vector<int>>> TestCase;

void test_game_of_life(TestCase& c) {
    auto [i, ans] = c;
    auto myAns = i;
    gameOfLife(myAns);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, game_of_life) {
    std::vector<TestCase> cases{
        {{{1, 1}, {1, 0}}, {{1, 1}, {1, 1}}},
        {{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}},
         {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}}},
    };

    for (TestCase& c : cases) {
        test_game_of_life(c);
    }
}
