// https://leetcode.cn/problems/course-schedule/ Course Schedule
#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct GraphNode {
    std::vector<int> neighbors{};
    int state{0};
};

inline void dfs(vector<GraphNode>& graph, int nodeId, bool& ringDetected) {
    if (ringDetected) {
        return;
    }

    auto& node = graph[nodeId];

    if (node.state == 1) {
        ringDetected = true;
        return;
    }
    if (node.state == 2) {
        return;
    }

    node.state = 1;
    for (auto& nnId : node.neighbors) {
        auto& nn = graph[nnId];
        dfs(graph, nnId, ringDetected);
        if (ringDetected) {
            return;
        }
    }
    node.state = 2;
}

inline bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<GraphNode> graph(numCourses, GraphNode());

    for (auto pair : prerequisites) {
        int dep = pair[1];
        int course = pair[0];
        graph[dep].neighbors.push_back(course);
    }

    bool ringDetected{false};
    for (int i = 0; i < graph.size(); ++i) {
        auto& node = graph[i];
        if (node.state == 2) {
            continue;
        }
        dfs(graph, i, ringDetected);
        if (ringDetected) {
            break;
        }
    }

    return !ringDetected;
}