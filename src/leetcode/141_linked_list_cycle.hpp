// https://leetcode.cn/problems/linked-list-cycle/ Linked List Cycle
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    ListNode *fast{head->next}, *slow{head};
    while (true) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next;
        if (fast == NULL) {
            return false;
        }
        fast = fast->next;
        if (fast == NULL) {
            return false;
        }
        slow = slow->next;
    }

    return false;
}