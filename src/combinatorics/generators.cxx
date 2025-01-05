#include "generators.hpp"

#include <cstdint>
#include <iostream>

bool Combinations::forward() {
    int64_t num_ones = 0;
    for (size_t i = 0; i < n; ++i) {
        if (num_ones > 0 && this->current[i] == 0) {
            this->current[i] = 1;
            for (size_t j = 0; j <= i - 1; ++j) {
                this->current[j] = (--num_ones) > 0 ? 1 : 0;
            }
            break;
        }

        if (this->current[i] == 1) {
            num_ones++;
        }
    }

    return num_ones != static_cast<int64_t>(r);
}

Combinations::Combinations(uint64_t _n, uint64_t _r) : n(_n), r(_r) {
    if (_n < _r) {
        throw std::invalid_argument("_n must be not be smaller than _r");
    }
    this->current = R_combination(this->n, false);
    for (size_t i = 0; i < this->r; ++i) {
        this->current[i] = true;
    }
}
