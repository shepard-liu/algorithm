// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/ Remove Nth
// Node From End of List
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

inline ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* cur{head};
    int size = 0;
    while (cur != nullptr) {
        cur = cur->next;
        size++;
    }

    int m = size - n;
    if (m == 0) {
        return head->next;
    }

    cur = head;
    for (int i = 0; i < m - 1; ++i) {
        cur = cur->next;
    }

    cur->next = cur->next->next;
    return head;
}