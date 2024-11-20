#include "prime_factors.hpp"

#include <cmath>
#include <utility>
#include <vector>

#include "is_prime.hpp"

std::vector<std::pair<uint64_t, uint64_t>> prime_factors(int64_t n) {
    n = std::abs(n);

    if (is_prime(n)) {
        return {{n, 1}};
    }

    std::vector<std::pair<uint64_t, uint64_t>> factors{};

    const uint64_t end = std::ceil(std::sqrt(n));
    for (uint64_t i = 2; i <= end && n != 1; ++i) {
        if (is_prime(i) == false) {
            continue;
        }
        std::pair<uint64_t, uint64_t> pair(i, 0);

        while (n % i == 0) {
            n /= i;
            pair.second++;
        }

        if (pair.second != 0) {
            factors.push_back(pair);
        }
    }

    return factors;
}
