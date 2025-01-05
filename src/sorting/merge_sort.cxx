#include "merge_sort.hpp"

#include <cstddef>
#include <vector>

void merge(std::vector<int>& array, size_t from1, size_t to1, size_t from2,
           size_t to2, std::vector<int>& tmp) {
    size_t i = 0, start = from1;
    while (from1 != to1 && from2 != to2) {
        if (array[from1] < array[from2]) {
            tmp[i++] = array[from1++];
        } else {
            tmp[i++] = array[from2++];
        }
    }

    while (from1 != to1) {
        tmp[i++] = array[from1++];
    }

    while (from2 != to2) {
        tmp[i++] = array[from2++];
    }

    for (size_t j = 0; j < i; ++j) {
        array[start + j] = tmp[j];
    }
}

void merge_sort_impl(std::vector<int>& array, size_t from, size_t to,
                     std::vector<int>& tmp) {
    if (from + 1 == to) {
        return;
    }

    size_t mid = (from + to) / 2;

    merge_sort_impl(array, from, mid, tmp);
    merge_sort_impl(array, mid, to, tmp);
    merge(array, from, mid, mid, to, tmp);
}

void merge_sort(std::vector<int>& array) {
    if (array.size() == 0) {
        return;
    }
    std::vector<int> tmp(array.size());
    merge_sort_impl(array, 0, array.size(), tmp);
}