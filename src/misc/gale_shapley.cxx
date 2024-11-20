#include "gale_shapley.hpp"

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <queue>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::pair<size_t, size_t>> gale_shapley(
    const std::vector<std::vector<size_t>>& initiatives,
    const std::vector<std::vector<size_t>>& passives) {
    size_t n = initiatives.size();

    // passives' ranking of initiatives
    std::vector<std::unordered_map<size_t, size_t>> rank(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            rank[i][passives[i][j]] = j;
        }
    }

    std::queue<size_t> free_initiatives;
    for (size_t i = 0; i < n; ++i) {
        free_initiatives.push(i);
    }

    std::unordered_map<size_t, size_t> pass_to_init;
    std::vector<size_t> next_proposal(n, 0);

    while (!free_initiatives.empty()) {
        size_t i = free_initiatives.front();

        size_t j = initiatives[i][next_proposal[i]];
        auto it = pass_to_init.find(j);
        next_proposal[i]++;

        if (it == pass_to_init.end()) {
            // this passive has not been matched
            pass_to_init.emplace(j, i);
            free_initiatives.pop();
        } else {
            size_t current_partner = it->second;
            if (rank[j][current_partner] > rank[j][i]) {
                // if i is prefered to the current initiative
                it->second = i;
                free_initiatives.pop();
                free_initiatives.push(current_partner);
            }
        }
    }

    std::vector<std::pair<size_t, size_t>> ans(n);
    std::transform(
        pass_to_init.begin(), pass_to_init.end(), ans.begin(),
        [](const std::pair<size_t, size_t>& pair) {
            return std::pair<size_t, size_t>{pair.second, pair.first};
        });
    return ans;
}
