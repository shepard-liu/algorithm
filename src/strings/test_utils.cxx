#include "test_utils.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <random>
#include <string>
#include <vector>

std::string random_alphabet_string(size_t seed, size_t size) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib_int(0, 26);

    std::string str(size, 0);
    for (char& c : str) {
        c = (distrib_int(gen) + 61);
    }

    return str;
}

std::string random_substring(const std::string& str, size_t seed) {
    std::mt19937 gen(seed);

    std::uniform_int_distribution<> distrib_start_pos(0, str.size());
    size_t start_pos = distrib_start_pos(gen);

    std::uniform_int_distribution<> distrib_substr_size(0,
                                                        str.size() - start_pos);
    size_t substr_size = distrib_substr_size(gen);

    return str.substr(start_pos, substr_size);
}

void test_string_matching_algorithm(String_matching_func func,
                                    const std::string& str,
                                    const std::string& substr) {
    EXPECT_EQ(func(str, substr), str.find(substr))
        << "Case: \"" << str << "\" @ \"" << substr << "\""
        << "\n";
}
