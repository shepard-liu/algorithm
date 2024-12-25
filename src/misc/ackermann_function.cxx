#include "ackermann_function.hpp"

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <utility>

#include "stack"

unsigned long ackermann_function(unsigned long m, unsigned long n) {
    if (m == 0) {
        return 2 * n;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    return ackermann_function(m - 1, ackermann_function(m, n - 1));
}

unsigned long ackermann_function_stack(unsigned long m, unsigned long n) {
    std::stack<std::pair<unsigned long, unsigned long>> stack;

    struct Hasher {
        size_t operator()(
            const std::pair<unsigned long, unsigned long>& pair) const {
            return (pair.first << 32) ^ pair.second;
        }
    };

    std::unordered_map<std::pair<unsigned long, unsigned long>, unsigned long,
                       Hasher>
        table{};

    stack.push({m, n});

    while (!stack.empty()) {
        auto [a, b] = stack.top();
        stack.pop();

        auto it = table.find({a, b});
        if (it != table.end()) {
            continue;
        }

        if (a == 0) {
            table[{a, b}] = 2 * b;
        } else if (b == 0) {
            table[{a, b}] = 0;
        } else if (b == 1) {
            table[{a, b}] = 2;
        } else {
            auto iter = table.find({a, b - 1});
            if (iter == table.end()) {
                stack.push({a, b});
                stack.push({a, b - 1});
                continue;
            }

            auto iter2 = table.find({a - 1, iter->second});
            if (iter2 == table.end()) {
                stack.push({a, b});
                stack.push({a - 1, iter->second});
                continue;
            }

            table[{a, b}] = iter2->second;
        }
    }

    return table[{m, n}];
}