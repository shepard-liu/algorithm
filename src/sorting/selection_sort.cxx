#include "selection_sort.hpp"

#include <cstddef>
#include <tuple>

void selection_sort(std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i; j < array.size(); ++j) {
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }

        std::swap(array[i], array[min_index]);
    }
}