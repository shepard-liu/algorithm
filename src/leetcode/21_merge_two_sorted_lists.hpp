// https://leetcode.cn/problems/merge-two-sorted-lists/ Merge Two Sorted Lists
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    ListNode *p1{list1}, *p2{list2}, *p1Prev{nullptr};

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val < p2->val) {
            p1Prev = p1;
            p1 = p1->next;
            continue;
        }
        ListNode* p2Next = p2->next;
        if (p1Prev == nullptr) {
            list1 = p2;
            p1Prev = list1;
        } else {
            p1Prev->next = p2;
            p1Prev = p2;
        }
        p2->next = p1;
        p2 = p2Next;
    }

    // p1prev is not nullptr
    while (p2 != nullptr) {
        p1Prev->next = p2;
        p2 = p2->next;
        p1Prev = p1Prev->next;
    }

    return list1;
}