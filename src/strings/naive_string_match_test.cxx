
#include "naive_string_match.hpp"

#include <gtest/gtest.h>

#include "test_utils.hpp"

TEST(strings, naive_string_match) {
    for (auto [str, substr] : String_matching_test_cases) {
        test_string_matching_algorithm(naive_string_match, str, substr);
    }
}