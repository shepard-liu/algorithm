#include "insertion_sort.hpp"

#include <cstddef>
#include <optional>

void insertion_sort(std::vector<int>& array) {
    for (size_t i = 1; i < array.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (array[i] < array[j]) {
                int temp = array[i];
                for (size_t k = i; k > j; --k) {
                    array[k] = array[k - 1];
                }
                array[j] = temp;
                break;
            }
        }
    }
}