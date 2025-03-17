#include "123_best_time_to_buy_and_sell_stock_iii.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, int> TestCase;

void test_best_time_to_buy_and_sell_stock_iii(TestCase& c) {
    auto [prices, ans] = c;
    auto myAns = maxProfit(prices);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, best_time_to_buy_and_sell_stock_iii) {
    TestCase c1{
        {5, 4, 3, 1, 2, 4, 7, 9, 8, 7, 4, 5, 6, 7, 6, 7, 8, 9, 10, 9, 7}, 14};
    TestCase c2{{3, 3, 5, 0, 0, 3, 1, 4}, 6};
    TestCase c3{{1, 2, 3, 4, 5}, 4};
    TestCase c4{{7, 6, 4, 3, 1}, 0};
    TestCase c5{{1}, 0};
    TestCase c6{{1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9}, 16};
    // std::vector<TestCase> cases{c6};
    std::vector<TestCase> cases{c1, c2, c3, c4, c5, c6};

    for (TestCase& c : cases) {
        test_best_time_to_buy_and_sell_stock_iii(c);
    }
}
