// https://leetcode.cn/problems/rotate-list/ Rotate List
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

inline ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0) {
        return head;
    }

    ListNode* p{head};

    int n = 0;
    while (p != nullptr) {
        n++;
        if (p->next == nullptr) {
            p->next = head;
            break;
        }
        p = p->next;
    }

    if (n == 0) {
        return head;
    }

    k = k % n;
    if (k == n) {
        return head;
    }

    p = head;
    for (int i = 0; i < n - k - 1; ++i) {
        p = p->next;
    }

    ListNode* tmp = p->next;
    p->next = nullptr;
    head = tmp;

    return head;
}