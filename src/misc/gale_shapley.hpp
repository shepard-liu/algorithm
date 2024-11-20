

#include <cstddef>
#include <utility>
#include <vector>

std::vector<std::pair<size_t, size_t>> gale_shapley(
    const std::vector<std::vector<size_t>>& initiatives,
    const std::vector<std::vector<size_t>>& passives);