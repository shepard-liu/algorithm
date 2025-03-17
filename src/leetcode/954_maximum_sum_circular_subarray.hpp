// https://leetcode.cn/problems/maximum-sum-circular-subarray/ Maximum Sum
// Circular Subarray
#include <algorithm>
#include <cstddef>
#include <deque>
#include <functional>
#include <limits>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Range;

struct Sums {
    int lSum{0};
    int rSum{0};
    int mSum{0};
    int iSum{0};

    Sums() {}

    Sums(int l, int r, int m, int i) : lSum(l), rSum(r), mSum(m), iSum(i) {}
};

struct RangeHash {
    size_t operator()(const Range& r) const {
        return (r.first << 16) ^ r.second;
    }
};

typedef unordered_map<Range, Sums, RangeHash> SegmentTree;

inline const Sums& getSums(int l, int r, vector<int>& nums, SegmentTree& tree) {
    auto it = tree.find({l, r});
    if (it != tree.end()) {
        return it->second;
    }
    if (l + 1 == r) {
        tree[{l, r}] = Sums(nums[l], nums[l], nums[l], nums[l]);
        return tree[{l, r}];
    }

    int n = nums.size();

    int mid = r > n ? n : (l + r) / 2;
    if (r > n) {
        r %= n;
    }

    const Sums& left = getSums(l, mid, nums, tree);
    const Sums& right = getSums(mid % n, r, nums, tree);

    tree[{l, r}] = Sums(max(left.lSum, left.iSum + right.lSum),
                        max(right.rSum, right.iSum + left.rSum),
                        max(max(left.mSum, right.mSum), left.rSum + right.lSum),
                        left.iSum + right.iSum);
    return tree[{l, r}];
}

inline int maxSubarraySumCircular_SegmentTree(vector<int>& nums) {
    SegmentTree segTree;
    int maxSum{std::numeric_limits<int>::min()};
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        maxSum = max(maxSum, getSums(i, i + n, nums, segTree).mSum);
    }
    return maxSum;
}

inline int maxSubarraySumCircular(vector<int>& nums) {
    // value, pos
    deque<pair<int, int>> monoQueue;

    int sum = 0;
    int ans = nums[0];
    int n = nums.size();

    monoQueue.push_back({0, 0});

    for (int i = 0; i < 2 * n; ++i) {
        int num = nums[i % n];
        sum += num;

        if (!monoQueue.empty() && monoQueue.front().second <= i - n) {
            monoQueue.pop_front();
        }

        ans = max(ans, sum - (monoQueue.empty() ? 0 : monoQueue.front().first));

        while (!monoQueue.empty() && monoQueue.back().first > sum) {
            monoQueue.pop_back();
        }

        monoQueue.push_back({sum, i});
    }

    return ans;
}