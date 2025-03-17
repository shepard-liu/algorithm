// https://leetcode.cn/problems/simplify-path/ Simplify Path
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline string simplifyPath(string path) {
    vector<string> parts{};

    int i = 1;
    while (i < path.size()) {
        for (; i < path.size() && path[i] == '/'; ++i) {
        }

        string part{};
        for (; i < path.size() && path[i] != '/'; ++i) {
            part += path[i];
        }

        if (part.empty()) {
            break;
        }

        if (part == ".") {
        } else if (part == "..") {
            if (parts.size() >= 1) {
                parts.erase(parts.end() - 1);
            }
        } else {
            parts.push_back(std::move(part));
        }
    }

    string ans = std::accumulate(
        parts.begin(), parts.end(), string(""),
        [](const string& accum, const string& p) { return accum + '/' + p; });
    return ans.empty() ? "/" : ans;
}