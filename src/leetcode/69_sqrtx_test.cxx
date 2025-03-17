#include "69_sqrtx.hpp"

#include <cmath>
#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

void test_sqrtx(TestCase& c) {
    auto n = c;
    int ans = sqrt(c);
    int myAns = mySqrt(c);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, sqrtx) {
    std::vector<TestCase> cases{0, 1,  2,  3,  4,   5,    6,   7,   8,
                                9, 10, 11, 12, 100, 1000, 400, 501, 63};

    for (TestCase& c : cases) {
        test_sqrtx(c);
    }
}
