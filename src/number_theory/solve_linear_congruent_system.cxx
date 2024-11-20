#include "solve_linear_congruent_system.hpp"

#include <numeric>
#include <utility>

#include "mod.hpp"
#include "modular_inverse.hpp"

uint64_t solve_linear_congruent_system(
    const std::vector<std::pair<int64_t, uint64_t>>& params) {
    uint64_t m = std::accumulate(
        params.begin(), params.end(), uint64_t(1),
        [](uint64_t acc, const std::pair<int64_t, uint64_t>& v) {
            return v.second * acc;
        });

    int64_t x = std::accumulate(
        params.begin(), params.end(), 0,
        [&](int64_t acc, const std::pair<int64_t, uint64_t>& v) {
            auto [a_i, m_i] = v;
            int64_t M_i = m / m_i;
            int64_t y_i = modular_inverse(M_i, m_i);
            return mod(acc + a_i * M_i * y_i, int64_t(m));
        });

    return x;
}