#include "is_prime.hpp"

#include <cmath>

bool is_prime(uint64_t n) {
    if (n == 0 || n == 1) {
        return false;
    }

    const uint64_t end = std::floor(std::sqrt(n));
    for (uint64_t i = 2; i <= end; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}