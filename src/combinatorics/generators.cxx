#include "generators.hpp"

#include <cstddef>
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

Permutations::Permutations_iterator& Permutations::it() { return iterator; }

Permutations::Permutations(uint64_t _n, uint64_t _r) : comb(_n, _r) {
    this->current.reserve(_r);
    if (comb.it() != comb.end()) {
        init_from_combination(*comb.it());
        ++comb.it();
    }
}

void Permutations::init_from_combination(
    const Combinations::R_combination& cb) {
    this->current.clear();
    if (cb.size() == 0) {
        return;
    }
    for (size_t i = cb.size(); i != size_t(-1); i--) {
        if (cb[i] == 1) {
            this->current.push_back(i);
        }
    }
}

bool Permutations::forward() {
    if (this->current.size() == 0) {
        return false;
    }
    size_t i = 1;

    while (i < current.size() && current[i] > current[i - 1]) {
        i++;
    }

    if (i == current.size()) {
        if (comb.it() == comb.end()) {
            return false;
        }
        init_from_combination(*comb.it());
        ++comb.it();
        return true;
    }

    size_t j = 0;
    while (j <= i - 1 && current[j] < current[i]) {
        j++;
    }

    std::swap(current[j], current[i]);

    // reorder [0] - [i-1]
    for (size_t m = 0; m < i / 2; ++m) {
        std::swap(current[m], current[i - m - 1]);
    }

    return true;
}

Permutations::Permutations_iterator
Permutations::Permutations_iterator::operator++() {
    if (!perm->forward()) {
        this->perm = nullptr;
    }
    return *this;
}

bool Permutations::Permutations_iterator::operator==(
    const Permutations_iterator& that) {
    return this->perm == that.perm;
}

bool Permutations::Permutations_iterator::operator!=(
    const Permutations_iterator& that) {
    return this->perm != that.perm;
}

Combinations::Combinations_iterator
Combinations::Combinations_iterator::operator++() {
    if (!comb->forward()) {
        this->comb = nullptr;
    }
    return *this;
}

bool Combinations::Combinations_iterator::operator==(
    const Combinations_iterator& that) {
    return this->comb == that.comb;
}

bool Combinations::Combinations_iterator::operator!=(
    const Combinations_iterator& that) {
    return this->comb != that.comb;
}
