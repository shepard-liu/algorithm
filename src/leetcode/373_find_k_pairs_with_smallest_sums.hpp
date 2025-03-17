// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/ Find K Pairs
// with Smallest Sums
#include <algorithm>
#include <array>
#include <cstddef>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef tuple<int, int, int> TupleType;

struct Comparator {
    bool operator()(const TupleType& a, const TupleType& b) const {
        return get<0>(a) > get<0>(b);
    }
};

struct Hasher {
    size_t operator()(const pair<int, int>& a) const {
        return a.first << 16 ^ a.second;
    }
};

inline vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                          vector<int>& nums2, int k) {
    priority_queue<TupleType, vector<TupleType>, Comparator> q;
    q.push({nums1[0] + nums2[0], 0, 0});

    vector<vector<int>> ans;
    unordered_set<pair<int, int>, Hasher> addedIndexes;
    addedIndexes.emplace(0, 0);

    int m = nums1.size(), n = nums2.size();

    while (!q.empty() && k != 0) {
        auto [_, i, j] = q.top();
        q.pop();
        k--;
        ans.push_back({nums1[i], nums2[j]});
        if (i + 1 < m && addedIndexes.find({i + 1, j}) == addedIndexes.end()) {
            q.push({nums1[i + 1] + nums2[j], i + 1, j});
            addedIndexes.emplace(i + 1, j);
        }
        if (j + 1 < n && addedIndexes.find({i, j + 1}) == addedIndexes.end()) {
            q.push({nums1[i] + nums2[j + 1], i, j + 1});
            addedIndexes.emplace(i, j + 1);
        }
    }

    return ans;
}