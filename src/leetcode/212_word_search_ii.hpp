// https://leetcode.cn/problems/word-search-ii/ Word Search II
#include <memory>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline int charIndex(char c) { return c - 'a'; }

inline char indexChar(int i) { return i + 'a'; }

class Trie {
    std::vector<std::shared_ptr<Trie>> children;
    bool isWord = false;

   public:
    Trie() { children = std::vector<std::shared_ptr<Trie>>(26, nullptr); }

    std::shared_ptr<Trie> branchChild(char c) {
        int idx = charIndex(c);
        if (children[idx] == nullptr) {
            children[idx] = std::make_shared<Trie>();
        }
        return children[idx];
    }

    std::shared_ptr<Trie> getChild(char c) { return children[charIndex(c)]; }

    bool hasChild(char c) {
        int idx = charIndex(c);
        return children[idx] != nullptr;
    }

    void setWord() { isWord = true; }

    bool word() { return isWord; }
};

inline void insert(std::shared_ptr<Trie> root, const string& word) {
    auto cur = root;
    for (char c : word) {
        cur = cur->branchChild(c);
    }
    cur->setWord();
}

inline bool withinRange(vector<vector<char>>& board, int i, int j) {
    int m = board.size(), n = board[0].size();
    return (i >= 0 && i < m && j >= 0 && j < n);
}

inline void dfs(vector<vector<char>>& board, int i, int j,
                unordered_set<string>& ans, string& path,
                std::shared_ptr<Trie> trie, vector<vector<bool>>& cellState) {
    if (!withinRange(board, i, j)) {
        return;
    }
    if (cellState[i][j] == true) {
        return;
    }
    char c = board[i][j];
    trie = trie->getChild(c);
    if (trie == nullptr) {
        return;
    }

    path.push_back(c);

    if (trie->word()) {
        ans.insert(path);
    }

    cellState[i][j] = true;

    dfs(board, i + 1, j, ans, path, trie, cellState);
    dfs(board, i - 1, j, ans, path, trie, cellState);
    dfs(board, i, j + 1, ans, path, trie, cellState);
    dfs(board, i, j - 1, ans, path, trie, cellState);

    cellState[i][j] = false;

    path.pop_back();
}

inline vector<string> findWords(vector<vector<char>>& board,
                                vector<string>& words) {
    std::shared_ptr<Trie> root = make_shared<Trie>();
    for (auto& w : words) {
        insert(root, w);
    }
    int m = board.size(), n = board[0].size();
    unordered_set<string> ans;
    string path;
    vector<vector<bool>> cellStateTmpl(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<vector<bool>> cellState(cellStateTmpl);
            dfs(board, i, j, ans, path, root, cellState);
        }
    }
    return vector<string>(ans.begin(), ans.end());
}