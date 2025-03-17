#include "146_lru_cache.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"

typedef int TestCase;

void dumpCache(LRUCache& cache) {
    auto dump = cache.dump();
    for (auto [k, v] : dump) {
        std::cout << "[" << k << " - " << v << "] ";
    }
    std::cout << std::endl;
}

void getCache(LRUCache& cache, int key) {
    std::cout << "get " << key << " = " << cache.get(key) << std::endl;
    dumpCache(cache);
}

void putCache(LRUCache& cache, int key, int val) {
    std::cout << "put " << key << "-" << val << std::endl;
    cache.put(key, val);
    dumpCache(cache);
}

TEST(leetcode, lru_cache) {
    LRUCache cache(2);
    putCache(cache, 1, 1);
    putCache(cache, 2, 2);
    getCache(cache, 1);
    putCache(cache, 3, 3);
    getCache(cache, 2);
    putCache(cache, 4, 4);
    getCache(cache, 1);
    getCache(cache, 3);
    getCache(cache, 4);
    // cache.put(2, 1);
    // cache.put(2, 2);
    // std::cout << "get 2: " << cache.get(2) << std::endl;
    // cache.put(1, 1);
    // cache.put(4, 1);
    // std::cout << "get 2: " << cache.get(2) << std::endl;
}
