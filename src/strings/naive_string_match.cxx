#include "naive_string_match.hpp"

#include <cstddef>

size_t naive_string_match(const std::string& str, const std::string& substr) {
    if (substr.size() > str.size()) {
        return std::string::npos;
    }

    for (size_t i = 0; i <= str.size() - substr.size(); ++i) {
        size_t j = 0;
        while (j < substr.size() && substr[j] == str[i + j]) {
            ++j;
        }
        if (j == substr.size()) {
            return i;
        }
    }

    return std::string::npos;
}