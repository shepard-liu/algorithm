#include "221_maximal_square.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<vector<char>>, int> TestCase;

void test_maximal_square(TestCase& c) {
    auto [matrix, ans] = c;
    auto myAns = maximalSquare(matrix);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, maximal_square) {
    TestCase c1{{{'1', '1', '1', '1', '0'},
                 {'1', '1', '1', '1', '0'},
                 {'1', '1', '1', '1', '1'},
                 {'1', '1', '1', '1', '1'},
                 {'0', '0', '1', '1', '1'}},
                16};
    std::vector<TestCase> cases{c1};

    for (TestCase& c : cases) {
        test_maximal_square(c);
    }
}
