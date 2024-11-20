#include "test_utils.hpp"

#include <cstddef>
#include <random>
#include <sstream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
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

std::vector<int> random_int_array(size_t size, size_t seed, int from, int to) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib_int(from, to);

    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = distrib_int(gen);
    }

    return arr;
}

void test_sorting_algorithm(Sort_func func, std::size_t seed,
                            std::size_t size) {
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
}