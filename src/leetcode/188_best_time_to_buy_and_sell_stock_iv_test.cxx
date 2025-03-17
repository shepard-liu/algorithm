#include "188_best_time_to_buy_and_sell_stock_iv.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"
typedef tuple<vector<int>, int, int> TestCase;

void test_best_time_to_buy_and_sell_stock_iv(TestCase& c) {
    auto [prices, k, ans] = c;
    auto myAns = maxProfit(k, prices);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, best_time_to_buy_and_sell_stock_iv) {
    TestCase c1{{3, 2, 6, 5, 0, 3}, 2, 7};
    TestCase c2{{2, 4, 1}, 2, 2};
    std::vector<TestCase> cases{c1, c2};

    for (TestCase& c : cases) {
        test_best_time_to_buy_and_sell_stock_iv(c);
    }
}
