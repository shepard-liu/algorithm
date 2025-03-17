// https://leetcode.cn/problems/reverse-linked-list-ii/ Reverse Linked List II
#include <stack>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *lp{head}, *lpPrev{nullptr};

    int numOps = right - left;

    while (--left != 0) {
        lpPrev = lp;
        lp = lp->next;
    }

    ListNode *next{lp->next}, *rp{lp};
    while (numOps-- != 0) {
        ListNode* tmp = next->next;
        next->next = lp;

        lp = next;
        next = tmp;
    }

    rp->next = next;

    if (lpPrev != nullptr) {
        lpPrev->next = lp;
        return head;
    } else {
        return lp;
    }
}