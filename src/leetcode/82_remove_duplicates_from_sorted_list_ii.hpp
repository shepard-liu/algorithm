// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/ Remove
// Duplicates from Sorted List II
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

inline ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *prevStart{dummy}, *prevEnd{dummy};

    while (prevStart->next != nullptr) {
        int count = 0;
        while (prevEnd->next != nullptr &&
               prevEnd->next->val == prevStart->next->val) {
            count++;
            prevEnd = prevEnd->next;
        }
        if (count > 1) {
            prevStart->next = prevEnd->next;
            prevEnd = prevStart;
        } else {
            prevStart = prevEnd;
        }
    }

    head = dummy->next;
    delete dummy;
    return head;
}