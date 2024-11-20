

#include "solve_linear_congruent_system.hpp"

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include "gtest/gtest.h"
#include "mod.hpp"

void test_solve_linear_congruent_system(
    const std::vector<std::pair<int64_t, uint64_t>>& params) {
    auto ans = solve_linear_congruent_system(params);

    uint64_t m =
        std::accumulate(params.begin(), params.end(), uint64_t(1),
                        [](auto acc, const auto& v) { return v.second * acc; });

    std::cout << "x === " << ans << " (mod " << m
              << ") is the solution of linear congruent system: " << std::endl;

    for (const auto& [ai, mi] : params) {
        std::cout << "x === " << ai << " (mod " << mi << ")" << std::endl;
        EXPECT_EQ(mod(ai, int64_t(mi)), ans % mi)
            << "Expected " << ans << " to be congruent to " << ai << " modulo "
            << mi;
    }
    std::cout << std::endl;

    EXPECT_TRUE(ans < m) << "solution should fall into [0, m). got: " << ans
                         << " m: " << m;
}

TEST(number_theory, solve_linear_congruent_system) {
    // accept any answer
    test_solve_linear_congruent_system({});

    test_solve_linear_congruent_system({{8, 9}});

    test_solve_linear_congruent_system({{2, 3}, {3, 5}, {2, 7}});
    test_solve_linear_congruent_system({{2, 3}, {1, 4}, {3, 5}});
    test_solve_linear_congruent_system({{1, 2}, {2, 3}, {3, 5}});
    test_solve_linear_congruent_system({{1, 2}, {1, 3}});
    test_solve_linear_congruent_system({{0, 5}, {1, 3}});
    test_solve_linear_congruent_system({{4, 5}, {2, 7}, {9, 11}});

    std::vector<std::vector<std::pair<int64_t, uint64_t>>> param_list{
        {{3, 4}, {6, 7}}, {{3, 4}, {5, 7}}, {{2, 4}, {0, 7}},
        {{0, 4}, {3, 7}}, {{2, 4}, {2, 7}}, {{2, 4}, {1, 7}},
        {{1, 4}, {1, 7}}, {{1, 4}, {0, 7}}, {{0, 4}, {0, 7}}};

    for (auto params : param_list) {
        test_solve_linear_congruent_system(params);
    }

    test_solve_linear_congruent_system({{2, 5}, {1, 7}});
    test_solve_linear_congruent_system({{-2, 5}, {1, 7}});
    test_solve_linear_congruent_system({{-2, 5}, {-1, 7}});
    test_solve_linear_congruent_system({{2, 5}, {-1, 7}});

    test_solve_linear_congruent_system({{1, 3}, {1, 5}, {3, 7}});
    test_solve_linear_congruent_system({{-1, 3}, {1, 5}, {3, 7}});
    test_solve_linear_congruent_system({{-1, 3}, {-1, 5}, {3, 7}});
    test_solve_linear_congruent_system({{-1, 3}, {-1, 5}, {-3, 7}});
    test_solve_linear_congruent_system({{1, 3}, {-1, 5}, {3, 7}});
    test_solve_linear_congruent_system({{1, 3}, {-1, 5}, {-3, 7}});
    test_solve_linear_congruent_system({{1, 3}, {1, 5}, {-3, 7}});
    test_solve_linear_congruent_system({{-1, 3}, {1, 5}, {-3, 7}});

    test_solve_linear_congruent_system({{65, 99}, {2, 98}, {51, 97}, {10, 95}});
}