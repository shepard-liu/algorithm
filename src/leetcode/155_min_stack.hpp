// https://leetcode.cn/problems/min-stack/ Min Stack
#include <stack>
#include <string>
#include <vector>
using namespace std;

class MinStack {
    vector<int> elemStack;
    stack<int> minElemIndexes;

   public:
    MinStack() {}

    void push(int val) {
        elemStack.push_back(val);
        if (minElemIndexes.empty() || val < elemStack[minElemIndexes.top()]) {
            minElemIndexes.push(elemStack.size() - 1);
        }
    }

    void pop() {
        if (elemStack.empty()) {
            return;
        }
        int poppedIndex = elemStack.size() - 1;
        elemStack.erase(elemStack.end() - 1);
        if (minElemIndexes.top() == poppedIndex) {
            minElemIndexes.pop();
        }
    }

    int top() { return elemStack.back(); }

    int getMin() { return elemStack[minElemIndexes.top()]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */