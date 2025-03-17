#include "binary_search.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

void test_binary_search(const std::vector<int>& arr, int target) {
    auto it = std::find(arr.begin(), arr.end(), target);
    size_t ans = binary_search(arr, target);
    if (it == arr.end()) {
        EXPECT_TRUE(ans == size_t(-1));
    } else {
        EXPECT_TRUE(ans == std::distance(arr.begin(), it));
    }
}

TEST(searching, binary_search) {
    std::vector<std::pair<std::vector<int>, int>> data{{{1, 3, 5, 7, 9}, 5},
                                                       {{2, 3, 6, 9, 10}, 4}};
    for (auto [arr, target] : data) {
        test_binary_search(arr, target);
    }

    for (size_t i = 0; i < 1000; ++i) {
        std::vector<int> random_arr = random_int_array(20, 0, 0, 20);
        int target = random_arr[1];
        std::sort(random_arr.begin(), random_arr.end());
        test_binary_search(random_arr, target);
    }
}