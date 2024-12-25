
#include "gale_shapley.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ostream>
#include <random>
#include <utility>
#include <vector>

typedef std::vector<std::vector<size_t>> pref_table;

std::ostream& operator<<(std::ostream& os, const pref_table& tb) {
    for (const auto& list : tb) {
        for (const size_t index : list) {
            os << index << ", ";
        }
        os << "\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::pair<size_t, size_t>& match) {
    os << "(" << match.first << ", " << match.second << ")";
    return os;
}

bool is_stable(const std::vector<std::vector<size_t>>& initiatives,
               const std::vector<std::vector<size_t>>& passives,
               const std::vector<std::pair<size_t, size_t>>& matches) {
    size_t n = initiatives.size();

    std::vector<size_t> initiative_partner(n, -1);
    std::vector<size_t> passive_partner(n, -1);
    for (const auto& match : matches) {
        initiative_partner[match.first] = match.second;
        passive_partner[match.second] = match.first;
    }

    for (size_t a = 0; a < n; ++a) {
        for (size_t b = 0; b < n; ++b) {
            if (initiative_partner[a] == b) {
                continue;
            }
            size_t current_b = initiative_partner[a];
            size_t current_a = passive_partner[b];

            auto it_a =
                std::find(initiatives[a].begin(), initiatives[a].end(), b);
            auto it_a_current = std::find(initiatives[a].begin(),
                                          initiatives[a].end(), current_b);
            bool a_prefers_b = (it_a < it_a_current);

            auto it_b = std::find(passives[b].begin(), passives[b].end(), a);
            auto it_b_current =
                std::find(passives[b].begin(), passives[b].end(), current_a);
            bool b_prefers_a = (it_b < it_b_current);

            if (a_prefers_b && b_prefers_a) {
                return false;
            }
        }
    }

    return true;
}

void test_gale_shapley(const pref_table& init, const pref_table& pass) {
    auto ans = gale_shapley(init, pass);

    ASSERT_EQ(ans.size(), init.size()) << "invalid number of pairs.";

    std::cout << "Initiative preference table:\n";
    std::cout << init;
    std::cout << "Passive preference table:\n";
    std::cout << pass;
    std::cout << "Answers:\n";

    std::sort(ans.begin(), ans.end());
    for (const auto& match : ans) {
        std::cout << match << "\n";
    }
    EXPECT_TRUE(is_stable(init, pass, ans)) << "unstable match found.";

    std::cout << "End of Answers\n" << std::endl;
}

TEST(misc, gale_shapley) {
    test_gale_shapley({{0, 1, 2}, {1, 2, 0}, {1, 0, 2}},
                      {{1, 2, 0}, {2, 0, 1}, {0, 1, 2}});
    test_gale_shapley({{2, 0, 1}, {0, 1, 2}, {1, 2, 0}},
                      {{0, 1, 2}, {1, 0, 2}, {2, 1, 0}});
    test_gale_shapley({{0, 1, 2}, {0, 1, 2}, {0, 1, 2}},
                      {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}});
    test_gale_shapley({{2, 1, 0}, {2, 1, 0}, {2, 1, 0}},
                      {{2, 1, 0}, {2, 1, 0}, {2, 1, 0}});

    const size_t n = 5;
    std::vector<size_t> indexes(n);
    std::iota(indexes.begin(), indexes.end(), 0);

    for (size_t seed = 0; seed < 1000; ++seed) {
        pref_table init;
        pref_table pass;
        init.reserve(n);
        pass.reserve(n);
        std::mt19937_64 rng(seed);

        for (size_t i = 0; i < n; ++i) {
            std::vector<size_t> shuffled(indexes);
            std::shuffle(shuffled.begin(), shuffled.end(), rng);
            init.push_back(shuffled);
            std::shuffle(shuffled.begin(), shuffled.end(), rng);
            pass.push_back(shuffled);
        }

        test_gale_shapley(init, pass);
    }
}