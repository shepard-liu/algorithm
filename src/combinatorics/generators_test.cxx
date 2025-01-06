
#include "generators.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

#include "counting.hpp"

std::ostream& operator<<(std::ostream& os,
                         const Combinations::R_combination& cb) {
    for (auto it = cb.rbegin(); it != cb.rend(); ++it) {
        os << (*it);
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const Permutations::R_permutation& perm) {
    for (auto it = perm.rbegin(); it != perm.rend(); ++it) {
        os << (*it);
    }
    return os;
}

uint64_t number_from_bits(const std::vector<bool>& bits) {
    uint64_t n = 0;
    for (size_t i = 0; i < bits.size(); ++i) {
        if (bits[i] == 0) {
            continue;
        }
        n = n | (1 << i);
    }
    return n;
}

bool operator<(const Permutations::R_permutation& left,
               const Permutations::R_permutation& right) {
    if (left.size() != right.size()) {
        return left.size() < right.size();
    }
    if (left.size() == 0) {
        return false;
    }
    for (size_t i = left.size() - 1; i != size_t(-1); --i) {
        if (left[i] != right[i]) {
            return left[i] < right[i];
        }
    }
    return false;
}

bool operator<=(const Permutations::R_permutation& left,
                const Permutations::R_permutation& right) {
    if (left.size() != right.size()) {
        return left.size() < right.size();
    }
    if (left.size() == 0) {
        return true;
    }
    for (size_t i = left.size() - 1; i != size_t(-1); --i) {
        if (left[i] != right[i]) {
            return left[i] < right[i];
        }
    }
    return true;
}

bool operator>=(const Permutations::R_permutation& left,
                const Permutations::R_permutation& right) {
    return right <= left;
}

bool operator>(const Permutations::R_permutation& left,
               const Permutations::R_permutation& right) {
    return right < left;
}

void test_generating_combinations(uint64_t n, uint64_t r) {
    Combinations gen(n, r);

    size_t count = 0;

    int64_t last = -1;
    for (auto it = gen.it(); it != gen.end(); ++it) {
        int64_t cur = number_from_bits(*it);
        size_t num_1s = std::count((*it).begin(), (*it).end(), 1);
        ASSERT_EQ(num_1s, r) << "Invalid number of elements: " << n << "," << r;
        ASSERT_LT(last, cur)
            << "Not in lexicographical order: " << n << "," << r;
        last = cur;
        count++;
    }

    ASSERT_EQ(binominal(n, r), count)
        << "Invalid number of combinations: " << n << "," << r;
}

void test_generating_permutations(uint64_t n, uint64_t r) {
    Permutations gen(n, r);

    size_t count = 0;

    for (auto it = gen.it(); it != gen.end(); ++it) {
        Permutations::R_permutation cur = *(it);
        // std::cout << cur << std::endl;
        ASSERT_EQ(cur.size(), r)
            << "Invalid number of elements: " << n << "," << r;
        count++;
    }

    ASSERT_EQ(binominal(n, r) * factorial(r), count)
        << "Invalid number of permutations: " << n << "," << r;
}

TEST(combinatorics, generate_combinations) {
    for (size_t n = 0; n <= 10; ++n) {
        for (size_t r = 0; r <= n; ++r) {
            test_generating_combinations(n, r);
        }
    }

    for (size_t n = 0; n <= 10; ++n) {
        for (size_t r = 0; r <= n; ++r) {
            test_generating_permutations(n, r);
        }
    }

    test_generating_permutations(8, 5);
}