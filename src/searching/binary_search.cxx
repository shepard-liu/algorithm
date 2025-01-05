#include "binary_search.hpp"

#include <cstddef>

size_t binary_search(const std::vector<int>& arr, int target, size_t from,
                     size_t to) {
    if (from == size_t(-1)) {
        from = 0;
    }
    if (to == size_t(-1)) {
        to = arr.size();
    }

    if (from == to) {
        return -1;
    }

    size_t mid = (from + to) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, to);
    } else {
        return binary_search(arr, target, from, mid - 1);
    }
}