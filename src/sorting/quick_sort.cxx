#include "quick_sort.hpp"

#include <cstddef>
#include <type_traits>
#include <vector>

void quick_sort_impl(std::vector<int>& array, size_t from, size_t to) {
    if (from == to) {
        return;
    }
    int first = array[from];

    size_t i = from;
    size_t j = to - 1;

    while (i < j) {
        while (i != j && array[j] >= first) {
            j--;
        }
        std::swap(array[i], array[j]);
        while (i != j && array[i] <= first) {
            i++;
        }
        std::swap(array[i], array[j]);
    }

    quick_sort_impl(array, from, i);
    quick_sort_impl(array, i + 1, to);
}

void quick_sort(std::vector<int>& array) {
    quick_sort_impl(array, 0, array.size());
}