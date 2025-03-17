// https://leetcode.cn/problems/sort-list/ Sort List
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

void mergeSort(ListNode* begin, ListNode* end, vector<int>& tmp) {
    if (begin == end || begin->next == end) {
        return;
    }
    ListNode *fast{begin}, *slow{begin};
    while (fast != end) {
        fast = fast->next;
        slow = slow->next;
        if (fast != end) {
            fast = fast->next;
        }
    }

    mergeSort(begin, slow, tmp);
    mergeSort(slow, end, tmp);
    tmp.clear();

    ListNode *l{begin}, *r{slow};
    while (l != slow && r != end) {
        if (l->val > r->val) {
            tmp.push_back(r->val);
            r = r->next;
        } else {
            tmp.push_back(l->val);
            l = l->next;
        }
    }

    while (l != slow) {
        tmp.push_back(l->val);
        l = l->next;
    }

    while (r != end) {
        tmp.push_back(r->val);
        r = r->next;
    }

    int i = 0;
    for (ListNode* cur = begin; cur != end; cur = cur->next) {
        cur->val = tmp[i++];
    }
}

inline ListNode* sortList(ListNode* head) {
    std::vector<int> tmp;
    mergeSort(head, nullptr, tmp);
    return head;
}