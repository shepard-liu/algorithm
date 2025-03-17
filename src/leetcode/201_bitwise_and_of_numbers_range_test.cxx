#include "201_bitwise_and_of_numbers_range.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<int, int, int> TestCase;

void test_bitwise_and_of_numbers_range(TestCase& c) {
    auto [left, right, ans] = c;
    auto myAns = rangeBitwiseAnd(left, right);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, bitwise_and_of_numbers_range) {
    std::vector<TestCase> cases{{5, 7, 4}, {0, 0, 0}, {1, 2147483647, 0}};

    for (TestCase& c : cases) {
        test_bitwise_and_of_numbers_range(c);
    }
}
