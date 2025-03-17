// https://leetcode.cn/problems/word-ladder/ Word Ladder
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline int ladderLength(string beginWord, string endWord,
                        vector<string>& wordList) {
    struct GraphNode {
        string word{};
        vector<int> neighbors{};
        int steps = 0;

        GraphNode(const string& g) : word(g) {}
    };

    std::vector<GraphNode> nodes;
    nodes.reserve(wordList.size() + 1);

    std::unordered_map<string, int> nodeMap{};

    wordList.push_back(beginWord);

    for (string& g : wordList) {
        if (nodeMap.find(g) == nodeMap.end()) {
            nodeMap[g] = nodes.size();
            nodes.push_back(GraphNode(g));
        }
    }

    if (nodeMap.find(endWord) == nodeMap.end()) {
        return 0;
    }

    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = i + 1; j < nodes.size(); ++j) {
            auto& n1 = nodes[i];
            auto& n2 = nodes[j];
            auto& s1 = n1.word;
            auto& s2 = n2.word;
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

    int startNodeId = nodeMap[beginWord], endNodeId = nodeMap[endWord];

    queue<int> q;
    q.push(startNodeId);

    while (!q.empty()) {
        int id = q.front();
        q.pop();
        auto& node = nodes[id];

        for (int nbId : node.neighbors) {
            if (nbId == endNodeId) {
                return node.steps + 1 + 1;
            }
            auto& nbNode = nodes[nbId];
            if (nbNode.steps > 0) {  // visited
                continue;
            }
            nbNode.steps = node.steps + 1;

            q.push(nbId);
        }
    }

    return 0;
}