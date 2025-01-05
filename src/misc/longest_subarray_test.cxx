#include "longest_subarray.hpp"

#include <iostream>
#include <vector>

#include "../sorting/test_utils.hpp"
#include "gtest/gtest.h"

TEST(misc, longest_subarray) {
    std::vector<std::vector<int>> data{{8, 11, 9, 1, 4, 6, 12, 10, 5, 7},
                                       {22, 5, 7, 2, 23, 10, 15, 21, 3, 17}};
    for (auto& arr : data) {
        std::cout << longest_subarray(arr) << std::endl;
        std::cout << "Length: " << longest_subarray_length(arr) << std::endl;
    }
}