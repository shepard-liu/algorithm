// https://leetcode.cn/problems/add-two-numbers/ Add Two Numbers
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1{l1}, *p2{l2}, *res{new ListNode()};
    ListNode *ans{res}, *last{res};

    int proceed = 0;
    while (p1 != nullptr || p2 != nullptr) {
        int a = p1 == nullptr ? 0 : p1->val;
        int b = p2 == nullptr ? 0 : p2->val;
        int sum = a + b + proceed;
        if (sum >= 10) {
            sum -= 10;
            proceed = 1;
        } else {
            proceed = 0;
        }

        res->val = sum;
        res->next = new ListNode();
        last = res;

        res = res->next;
        p1 = p1 == nullptr ? nullptr : p1->next;
        p2 = p2 == nullptr ? nullptr : p2->next;
    }

    if (proceed == 1) {
        res->val = 1;
    }

    if (res->val == 0) {
        last->next = nullptr;
    }

    return ans;
}