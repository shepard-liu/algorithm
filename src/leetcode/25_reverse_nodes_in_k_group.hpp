// https://leetcode.cn/problems/reverse-nodes-in-k-group/ Reverse Nodes in
// k-Group
#include <string>
#include <vector>
using namespace std;
#include "./92_reverse_linked_list_ii.hpp"

inline bool hasKMoreElement(ListNode* head, int k) {
    while (head != nullptr) {
        head = head->next;
        k--;
        if (k <= 0) {
            return true;
        }
    }
    return k <= 0;
}

inline ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
        return head;
    }
    ListNode* cur{head};
    ListNode* prev{nullptr};
    bool firstReverse{true};
    while (hasKMoreElement(cur, k)) {
        ListNode* newHead = reverseBetween(cur, 1, k);
        if (firstReverse) {
            head = newHead;
            firstReverse = false;
        } else {
            prev->next = newHead;
        }
        prev = cur;
        cur = cur->next;
    }

    return head;
}