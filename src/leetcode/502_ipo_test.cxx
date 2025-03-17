#include "502_ipo.hpp"

#include <iostream>
#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<int, int, vector<int>, vector<int>, int> TestCase;

void test_ipo(TestCase& c) {
    auto [k, w, profits, capitals, ans] = c;
    std::cout << "k: " << k << " w: " << w << '\n';
    std::cout << "profits: " << profits << '\n';
    std::cout << "capitals: " << capitals << '\n';
    auto myAns = findMaximizedCapital(k, w, profits, capitals);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, ipo) {
    TestCase c1{3, 0, {1, 3, 1, 2, 4}, {0, 1, 4, 3, 2}, 8};
    TestCase c2{1, 0, {1, 2, 3}, {1, 1, 2}, 0};
    std::vector<TestCase> cases{c1, c2};

    for (TestCase& c : cases) {
        test_ipo(c);
    }
}
