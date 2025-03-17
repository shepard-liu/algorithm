// https://leetcode.cn/problems/generate-parentheses/ Generate Parentheses
#include <string>
#include <vector>
using namespace std;

inline void dfs(int depth, vector<string>& ans, string& path, int n) {
    if (depth > n || depth < 0) {
        return;
    }
    if (path.size() == 2 * n) {
        if (depth == 0) {
            ans.push_back(path);
        }
        return;
    }

    path.push_back('(');
    dfs(depth + 1, ans, path, n);
    path.pop_back();

    path.push_back(')');
    dfs(depth - 1, ans, path, n);
    path.pop_back();
}

inline vector<string> generateParenthesis(int n) {
    vector<string> ans{};
    string path{};
    dfs(0, ans, path, n);
    return ans;
}