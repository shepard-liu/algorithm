// https://leetcode.cn/problems/minimum-genetic-mutation/ Minimum Genetic
// Mutation
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline int minMutation(string startGene, string endGene, vector<string>& bank) {
    struct GraphNode {
        string gene{};
        vector<int> neighbors{};
        int steps = 0;

        GraphNode(const string& g) : gene(g) {}
    };

    std::vector<GraphNode> nodes;
    nodes.reserve(bank.size() + 1);

    std::unordered_map<string, int> nodeMap{};

    bank.push_back(startGene);

    for (string& g : bank) {
        if (nodeMap.find(g) == nodeMap.end()) {
            nodeMap[g] = nodes.size();
            nodes.push_back(GraphNode(g));
        }
    }

    if (nodeMap.find(endGene) == nodeMap.end()) {
        return -1;
    }

    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = i + 1; j < nodes.size(); ++j) {
            auto& n1 = nodes[i];
            auto& n2 = nodes[j];
            auto& s1 = n1.gene;
            auto& s2 = n2.gene;
            bool changedOne = false;
            for (int k = 0; k < s1.size(); ++k) {
                if (s1[k] != s2[k]) {
                    if (changedOne == false) {
                        changedOne = true;
                    } else {
                        changedOne = false;
                        break;
                    }
                }
            }
            if (!changedOne) {
                continue;
            }
            n1.neighbors.push_back(j);
            n2.neighbors.push_back(i);
        }
    }

    int startNodeId = nodeMap[startGene], endNodeId = nodeMap[endGene];

    queue<int> q;
    q.push(startNodeId);

    while (!q.empty()) {
        int id = q.front();
        q.pop();
        auto& node = nodes[id];

        for (int nbId : node.neighbors) {
            if (nbId == endNodeId) {
                return node.steps + 1;
            }
            auto& nbNode = nodes[nbId];
            if (nbNode.steps > 0) {  // visited
                continue;
            }
            nbNode.steps = node.steps + 1;

            q.push(nbId);
        }
    }

    return -1;
}