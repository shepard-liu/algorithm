
#include <cstddef>
#include <iostream>
#include <ostream>
#include <random>
#include <sstream>
#include <vector>

#include "gtest/gtest.h"

inline std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
    os << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];

        if (i != vec.size() - 1) {
            os << ", ";
        }
    }

    os << "]";
    return os;
}

/**
 * @brief Generator uniformly distributed random integers.
 *
 * @param size
 * @param seed default: 0
 * @param from default: 0
 * @param to default: 10
 * @return std::vector<int>
 */
inline std::vector<int> random_int_array(size_t size, size_t seed = 0,
                                         int from = 0, int to = 10) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib_int(from, to);

    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = distrib_int(gen);
    }

    return arr;
}

typedef void (*Sort_func)(std::vector<int> &);

inline void test_sorting_algorithm(Sort_func func, std::size_t seed,
                                   std::size_t size = 10,
                                   bool verbose = false) {
    std::stringstream ss;
    std::vector<int> array = random_int_array(size, seed, 0, size);

    ss << "Case(" << seed << "): " << array << "\n";

    std::vector<int> expected(array);

    func(array);

    std::sort(expected.begin(), expected.end(),
              [](const int &a, const int &b) { return a < b; });

    bool is_equal = std::equal(array.begin(), array.end(), expected.begin(),
                               expected.end());

    ss << "Got: " << array << "\n"
       << "Expected: " << expected;

    EXPECT_TRUE(is_equal) << ss.str();
    if (verbose) {
        std::cout << ss.str() << std::endl;
    }
}
