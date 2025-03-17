#include "quick_sort.hpp"

#include <cstddef>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

TEST(sorting, quick_sort) {
    for (size_t i = 0; i < 100; ++i) {
        test_sorting_algorithm(quick_sort, i);
    }
}