#include "6_zigzag_conversion.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<string, size_t, string> TestCase;

void test_zigzag_conversion(TestCase& c) {
    auto [input, numRows, output] = c;
    string ans = convert(input, numRows);
    std::cout << input << "(" << numRows << ")" << std::endl;
    EXPECT_EQ(ans, output);
}

TEST(leetcode, zigzag_conversion) {
    std::vector<TestCase> cases{
        {"abcdefghijklmno", 5, "aibhjcgkodflnem"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
    };

    for (TestCase& c : cases) {
        test_zigzag_conversion(c);
    }
}
