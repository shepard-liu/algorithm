#include "merge_sort.hpp"

#include <cstddef>

#include "test_utils.hpp"

TEST(sorting, merge_sort) {
    for (size_t i = 0; i < 10; ++i) {
        test_sorting_algorithm(merge_sort, i, 10, true);
    }
}