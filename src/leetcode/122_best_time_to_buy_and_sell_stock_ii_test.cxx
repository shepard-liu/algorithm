#include "122_best_time_to_buy_and_sell_stock_ii.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_best_time_to_buy_and_sell_stock_ii(TestCase& c) {
    std::cout << "Max Profit for " << c << " : " << maxProfit(c) << std::endl;
}

TEST(leetcode, best_time_to_buy_and_sell_stock_ii) {
    std::vector<TestCase> cases{
        {7, 1, 5, 3, 6, 4},  // Test case 1
        {1, 2, 3, 4, 5},     // Test case 2
        {7, 6, 4, 3, 1},     // Test case 3
        {1, 7, 2, 8, 3, 9},  // Test case 4
        {2, 4, 1, 7, 5, 3}   // Test case 5
    };

    for (TestCase& c : cases) {
        test_best_time_to_buy_and_sell_stock_ii(c);
    }
}
