// https://leetcode.cn/problems/evaluate-division/ Evaluate Division
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

typedef string Key;
typedef double Value;

class DisjointSets {
    struct ElementData {
        int parent;
        Value val;

        ElementData(int par, const Value& v) : parent(par), val(v) {}
    };

    vector<ElementData> data{};
    unordered_map<string, int> nodeMap{};
    vector<int> rank{};

   private:
    int find(int idx) {
        if (data[idx].parent != idx) {
            data[idx].parent = find(data[idx].parent);
        }
        return data[idx].parent;
    }

   public:
    DisjointSets() {}

    void reserve(size_t n) {
        data.reserve(n);
        nodeMap.reserve(n);
        rank.reserve(n);
    }

    void makeSet(const Key& key, const Value& val) {
        if (nodeMap.find(key) != nodeMap.end()) {
            throw std::invalid_argument("Key \"" + key + "\" already exists");
        }
        int idx = data.size();
        data.push_back(ElementData(idx, val));
        rank.push_back(0);
        nodeMap[key] = idx;
    }

    const Value& get(const Key& key) const { return data[nodeMap.at(key)].val; }

    void set(const Key& key, const Value& val) {
        data[nodeMap.at(key)].val = val;
    }

    std::vector<std::pair<Key, Value>> getAll(const Key& key) {
        int par = find(nodeMap.at(key));
        std::vector<std::pair<Key, Value>> ret{};

        for (const auto& [k, idx] : nodeMap) {
            if (find(nodeMap.at(k)) == par) {
                ret.push_back({k, data[nodeMap.at(k)].val});
            }
        }
        return ret;
    }

    bool has(const Key& key) { return nodeMap.find(key) != nodeMap.end(); }

    bool sameSet(const Key& k1, const Key& k2) {
        int idx1 = nodeMap.at(k1);
        int idx2 = nodeMap.at(k2);
        return find(idx1) == find(idx2);
    }

    void merge(const Key& k1, const Key& k2) {
        int idx1 = find(nodeMap.at(k1));
        int idx2 = find(nodeMap.at(k2));
        if (idx1 == idx2) {
            return;
        }

        if (rank[idx1] > rank[idx2]) {
            data[idx2].parent = idx1;
        } else if (rank[idx1] < rank[idx2]) {
            data[idx1].parent = idx2;
        } else {
            data[idx1].parent = idx2;
            rank[idx2]++;
        }
    }

    std::vector<std::vector<std::pair<Key, Value>>> dump() {
        std::vector<std::vector<std::pair<Key, Value>>> d;
        std::unordered_map<int, int> parentToGroupIndex{};
        for (const auto& [key, idx] : nodeMap) {
            int par = find(idx);
            if (parentToGroupIndex.find(par) == parentToGroupIndex.end()) {
                parentToGroupIndex[par] = d.size();
                d.push_back({});
            }
            d[parentToGroupIndex[par]].push_back({key, data[idx].val});
        }
        return d;
    }
};

inline vector<double> calcEquation(vector<vector<string>>& equations,
                                   vector<double>& values,
                                   vector<vector<string>>& queries) {
    int n = values.size();

    DisjointSets ds;
    ds.reserve(n);
    for (int i = 0; i < n; ++i) {
        vector<string>& eq = equations[i];
        string& s1 = eq[0];
        string& s2 = eq[1];
        double val = values[i];

        if (!ds.has(s1) && !ds.has(s2)) {
            ds.makeSet(s1, 1);
        }

        if (!ds.has(s1)) {
            ds.makeSet(s1, ds.get(s2) * val);
        } else if (!ds.has(s2)) {
            ds.makeSet(s2, ds.get(s1) / val);
        } else if (ds.sameSet(s1, s2) == false) {
            double v1 = ds.get(s1);
            double v2 = ds.get(s2);
            double newV2 = v1 / val;
            double multiplier = newV2 / v2;
            auto group = ds.getAll(s2);
            for (auto& [k, _] : group) {
                ds.set(k, multiplier * ds.get(k));
            }
        }
        ds.merge(s1, s2);
    }

    std::vector<double> ans{};
    ans.reserve(queries.size());

    for (vector<string>& q : queries) {
        string& s1 = q[0];
        string& s2 = q[1];

        if ((!ds.has(s1) || !ds.has(s2)) || (!ds.sameSet(s1, s2))) {
            ans.push_back(-1);
            continue;
        }

        ans.push_back(ds.get(s1) / ds.get(s2));
    }

    return ans;
}