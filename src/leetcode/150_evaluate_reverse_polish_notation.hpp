// https://leetcode.cn/problems/evaluate-reverse-polish-notation/ Evaluate
// Reverse Polish Notation
#include <cctype>
#include <stack>
#include <string>
#include <vector>
using namespace std;

inline int evalRPN(vector<string>& tokens) {
    stack<int> exprs{};
    for (const auto& t : tokens) {
        if (std::isdigit(t.back())) {
            int n = std::stoi(t);
            exprs.push(n);
        } else {
            int op2 = exprs.top();
            exprs.pop();
            int op1 = exprs.top();
            exprs.pop();

            int res{};
            switch (t[0]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            exprs.push(res);
        }
    }

    return exprs.top();
}