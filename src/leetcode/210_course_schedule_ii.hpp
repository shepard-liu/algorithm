// https://leetcode.cn/problems/course-schedule-ii/ Course Schedule II
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

struct GraphNode {
    std::vector<int> neighbors;
    int state = 0;

    GraphNode() {}
};

inline void dfs(std::vector<GraphNode>& nodes, int nodeId, bool& hasRing,
                std::vector<int>& order) {
    if (hasRing) {
        return;
    }

    GraphNode& node = nodes[nodeId];

    if (node.state == 2) {
        return;
    } else if (node.state == 1) {
        hasRing = true;
        return;
    }

    node.state = 1;

    for (int nn : node.neighbors) {
        dfs(nodes, nn, hasRing, order);
        if (hasRing) {
            return;
        }
    }

    node.state = 2;
    order.push_back(nodeId);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<GraphNode> nodes(numCourses, GraphNode());
    for (auto& edge : prerequisites) {
        int to = edge[0];
        int from = edge[1];
        nodes[from].neighbors.push_back(to);
    }

    bool hasRing = false;
    vector<int> ans{};
    ans.reserve(numCourses);
    for (int i = 0; i < nodes.size(); ++i) {
        auto& node = nodes[i];
        if (node.state != 0) {
            continue;
        }
        dfs(nodes, i, hasRing, ans);
        if (hasRing) {
            return {};
        }
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}