// https://leetcode.cn/problems/partition-list/ Partition List
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

inline ListNode* partition(ListNode* head, int x) {
    ListNode *dummyLeft = new ListNode(x - 1, nullptr),
             *dummyRight = new ListNode(x, nullptr);

    ListNode *p{head}, *l{dummyLeft}, *r{dummyRight};

    while (p != nullptr) {
        if (p->val < x) {
            l->next = p;
            l = l->next;
        } else {
            r->next = p;
            r = r->next;
        }
        p = p->next;
    }

    l->next = dummyRight->next;
    r->next = nullptr;
    head = dummyLeft->next;
    delete dummyLeft;
    delete dummyRight;
    return head;
}