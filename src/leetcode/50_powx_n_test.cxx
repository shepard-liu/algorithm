#include "50_powx_n.hpp"

#include <cmath>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<double, int> TestCase;

void test_powx_n(TestCase& c) {
    auto [x, n] = c;
    auto ans = std::pow(x, n);
    auto myAns = myPow(x, n);
    EXPECT_NEAR(myAns, ans, 1e-5);
}

TEST(leetcode, powx_n) {
    std::vector<TestCase> cases{{2, 10}, {3, 12}, {-2, -5}, {-3, 12}};

    for (TestCase& c : cases) {
        test_powx_n(c);
    }
}
