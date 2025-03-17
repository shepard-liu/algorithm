#include "121_best_time_to_buy_and_sell_stock.hpp"

#include <limits>
#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_best_time_to_buy_and_sell_stock(TestCase& c) {
    int expected_profit = maxProfit(c);
    int min_price = std::numeric_limits<int>::max();
    int max_profit = 0;

    for (int price : c) {
        if (price < min_price) {
            min_price = price;
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }

    ASSERT_EQ(expected_profit, max_profit);
}

TEST(leetcode, best_time_to_buy_and_sell_stock) {
    std::vector<TestCase> cases{{7, 1, 5, 3, 6, 4},
                                {7, 6, 4, 3, 1},
                                {1, 2, 3, 4, 5},
                                {5, 4, 3, 2, 1},
                                {2, 4, 1, 7, 5, 3}};

    for (TestCase& c : cases) {
        test_best_time_to_buy_and_sell_stock(c);
    }
}
