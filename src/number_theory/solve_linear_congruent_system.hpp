
#include <cstdint>
#include <utility>
#include <vector>

/**
 * @brief Solve linear congruent system
 *
 * @param params pairs of a_i and m_i. m_i's are required to be relatively
 * prime.
 * @return modular m solution of the system.
 */
uint64_t solve_linear_congruent_system(
    const std::vector<std::pair<int64_t, uint64_t>>& params);