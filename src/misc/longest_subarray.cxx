#include "longest_subarray.hpp"

#include <algorithm>
#include <cstddef>
#include <limits>
#include <vector>

std::vector<int> longest_subarray_impl(const std::vector<int>& array, size_t i,
                                       std::vector<int> subarray) {
    if (i == array.size()) {
        return subarray;
    }
    std::vector<int> sub_pushed(subarray);
    if (subarray.size() == 0 || array[i] >= subarray.back()) {
        sub_pushed.push_back(array[i]);
    }

    std::vector<int> sub1;
    if (sub_pushed.size() > subarray.size()) {
        sub1 = longest_subarray_impl(array, i + 1, sub_pushed);
    }
    std::vector<int> sub2 = longest_subarray_impl(array, i + 1, subarray);
    if (sub1.size() > sub2.size()) {
        return sub1;
    } else {
        return sub2;
    }
}

std::vector<int> longest_subarray(const std::vector<int>& array) {
    return longest_subarray_impl(array, 0, {});
}

size_t longest_subarray_length_impl(const std::vector<int>& array, size_t i,
                                    int n) {
    if (i == array.size()) {
        return 0;
    }
    size_t sub1_max = 0;
    if (array[i] >= n) {
        sub1_max = longest_subarray_length_impl(array, i + 1, array[i]) + 1;
    }

    size_t sub2_max = longest_subarray_length_impl(array, i + 1, n);

    return std::max(sub1_max, sub2_max);
}

size_t longest_subarray_length(const std::vector<int>& array) {
    return longest_subarray_length_impl(array, 0,
                                        std::numeric_limits<int>::min());
}