#include "quick_sort.hpp"

#include <cstddef>

#include "gtest/gtest.h"
#include "test_utils.hpp"

TEST(sorting, quick_sort) {
    for (size_t i = 0; i < 100; ++i) {
        test_sorting_algorithm(quick_sort, i);
    }
}