// https://leetcode.cn/problems/valid-parentheses/ Valid Parentheses
#include <stack>
#include <string>
#include <vector>
using namespace std;

int getType(char c) {
    switch (c) {
        case '{':
            return 1;
        case '}':
            return -1;
        case '[':
            return 2;
        case ']':
            return -2;
        case '(':
            return 3;
        case ')':
            return -3;
    }
    return 0;
}

inline bool isValid(string s) {
    std::stack<int> brackets{};

    for (auto c : s) {
        int type = getType(c);
        if (brackets.empty()) {
            if (type < 0) {
                return false;
            }
            brackets.push(type);
            continue;
        }

        if (type > 0) {
            brackets.push(type);
            continue;
        }

        if (brackets.top() + type != 0) {
            return false;
        }
        brackets.pop();
    }

    return brackets.empty();
}