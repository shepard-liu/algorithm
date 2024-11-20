#include "bubble_sort.hpp"

void bubble_sort(std::vector<int> &array) {
    if (array.size() == 0) {
        return;
    }

    for (std::size_t i = 0; i < array.size() - 1; i++) {
        for (std::size_t j = 0; j < array.size() - i; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}