#include "67_add_binary.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<string, string> TestCase;

void test_add_binary(TestCase& c) {
    auto [a, b] = c;
    auto myAns = addBinary(a, b);
    std::cout << a << " + " << b << " = " << myAns << std::endl;
}

TEST(leetcode, add_binary) {
    std::vector<TestCase> cases{
        {"1010111", "1111111"}, {"11", "0"}, {"0", "0"}, {"1111101", "101"}};

    for (TestCase& c : cases) {
        test_add_binary(c);
    }
}
