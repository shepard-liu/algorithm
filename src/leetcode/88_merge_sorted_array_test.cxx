#include "88_merge_sorted_array.hpp"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

void test_merge_sorted_array(std::pair<vector<int>, vector<int>>& c) {
    c.first.resize(c.first.size() + c.second.size(), 0);

    std::cout << "m=" << c.first.size() << ";n=" << c.second.size()
              << std::endl;

    merge(c.first, c.first.size() - c.second.size(), c.second, c.second.size());

    for (int i = 1; i < (int)c.first.size(); ++i) {
        EXPECT_TRUE(c.first[i] >= c.first[i - 1]) << "Invalid order";
    }

    std::cout << "result:" << c.first << std::endl;
}

TEST(leetcode, merge_sorted_array) {
    vector<std::pair<vector<int>, vector<int>>> cases{
        {{1, 2, 3}, {2, 5, 6}},
        {{1}, {}},
        {{}, {1}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0}},
        {{1, 4, 7, 89}, {0, 9, 12, 53, 112}}};
    for (auto c : cases) {
        test_merge_sorted_array(c);
    }
}
