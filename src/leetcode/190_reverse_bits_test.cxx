#include "190_reverse_bits.hpp"

#include <bitset>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

#include "../test_utils.hpp"
typedef uint32_t TestCase;

void test_reverse_bits(TestCase& c) {
    auto myAns = reverseBits(c);
    std::cout << "case : " << std::bitset<32>(c).to_string()
              << "\nmyAns: " << std::bitset<32>(myAns).to_string() << std::endl;
}

TEST(leetcode, reverse_bits) {
    std::vector<TestCase> cases{0b00000010100101000001111010011100};

    for (TestCase& c : cases) {
        test_reverse_bits(c);
    }
}
