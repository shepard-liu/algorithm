// https://leetcode.cn/problems/lru-cache/ LRU Cache
#include <cstddef>
#include <iterator>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class LRUCache {
    typedef std::list<pair<int, int>>::iterator NodeIt;
    unordered_map<int, NodeIt> lookup{};
    list<pair<int, int>> items;
    size_t cap{1};

    void update(NodeIt it) { items.splice(items.begin(), items, it); }

   public:
    LRUCache(size_t capacity) : cap(capacity) {}

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return -1;
        }
        update(it->second);
        return (*it->second).second;
    }

    void put(int key, int val) {
        if (auto it = lookup.find(key); it != lookup.end()) {
            update(it->second);
            it->second->second = val;
        } else if (lookup.size() == cap) {
            auto oldest = std::prev(items.end());
            lookup.erase(oldest->first);
            oldest->first = key;
            oldest->second = val;
            lookup[key] = oldest;
            update(oldest);
        } else {
            items.push_front({key, val});
            lookup[key] = items.begin();
        }
    }

    std::vector<pair<int, int>> dump() {
        return vector<pair<int, int>>(items.begin(), items.end());
    }
};
