
#include "selection_sort.hpp"

#include "test_utils.hpp"

TEST(sorting, selection_sort) {
    for (size_t i = 0; i < 5; ++i) {
        test_sorting_algorithm(selection_sort, i);
    }
    test_sorting_algorithm(selection_sort, 0, 0);
    test_sorting_algorithm(selection_sort, 0, 1);
}