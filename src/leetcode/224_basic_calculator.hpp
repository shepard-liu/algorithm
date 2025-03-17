// https://leetcode.cn/problems/basic-calculator/ Basic Calculator
#include <cctype>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "../test_utils.hpp"
using namespace std;

enum Operator {
    Negative,
    Minus,
    Plus,
    Multiply,
    Divide,
    Bracket,
};

std::vector<string> tokenizeExpression(const string& s) {
    std::vector<string> tokens{};
    for (int i = 0; i < s.size(); ++i) {
        if (std::isdigit(s[i])) {
            int j = i + 1;
            while (std::isdigit(s[j])) {
                j++;
            }
            tokens.push_back(s.substr(i, j - i));
            i = j - 1;
        } else if (s[i] == ' ') {
        } else {
            tokens.push_back(std::string({s[i]}));
        }
    }
    return tokens;
}

Operator getType(const string& op, const string& lastToken) {
    if (op == "-" && std::isdigit(lastToken.back()) == false &&
        lastToken != ")") {
        return Negative;
    }
    switch (op[0]) {
        case '+':
            return Plus;
        case '-':
            return Minus;
        case '*':
            return Multiply;
        case '/':
            return Divide;
        case '(':
        case ')':
            return Bracket;
    }
    return Plus;
}

int getPriority(Operator op) {
    switch (op) {
        case Plus:
        case Minus:
            return 3;
        case Multiply:
        case Divide:
            return 2;
        case Negative:
            return 1;
        case Bracket:
            return 0;
    }
    return 0;
}

void evalOne(stack<int>& exprs, stack<Operator>& ops) {
    if (ops.top() == Negative) {
        exprs.top() = -exprs.top();
        ops.pop();
        return;
    }
    int op2 = exprs.top();
    exprs.pop();
    int op1 = exprs.top();
    exprs.pop();
    Operator op = ops.top();
    ops.pop();
    int res{};
    switch (op) {
        case Plus:
            res = op1 + op2;
            break;
        case Minus:
            res = op1 - op2;
            break;
        case Multiply:
            res = op1 * op2;
            break;
        case Divide:
            res = op1 / op2;
            break;
        case Negative:
        case Bracket:
            break;
    }
    exprs.push(res);
}

int calculate(string s) {
    // tokenize
    auto tokens = tokenizeExpression(s);

    stack<int> exprs;
    stack<Operator> ops;

    for (int i = 0; i < tokens.size(); ++i) {
        const string& t = tokens[i];
        if (std::isdigit(t.back())) {
            int n = std::stoi(t);
            exprs.push(n);
        } else if (t == "(") {
            ops.push(Bracket);
        } else if (t == ")") {
            Operator op = ops.top();
            while (op != Bracket) {
                evalOne(exprs, ops);
                op = ops.top();
            }
            ops.pop();
        } else {
            Operator op = getType(t, i - 1 >= 0 ? tokens[i - 1] : "(");
            int pri = getPriority(op);
            while (!ops.empty() && ops.top() != Bracket &&
                   getPriority(ops.top()) <= pri) {
                evalOne(exprs, ops);
            }
            ops.push(op);
        }
    }

    while (!ops.empty()) {
        evalOne(exprs, ops);
    }

    return exprs.top();
}