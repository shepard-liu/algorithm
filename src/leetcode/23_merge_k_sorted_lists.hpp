// https://leetcode.cn/problems/merge-k-sorted-lists/ Merge k Sorted Lists
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

inline ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    if (list1->val > list2->val) {
        std::swap(list1, list2);
    }
    ListNode* head = list1;
    while (list1 != nullptr && list2 != nullptr) {
        while (list1->next != nullptr && list1->next->val <= list2->val) {
            list1 = list1->next;
        }
        auto list1Next = list1->next;
        auto list2Next = list2->next;
        list1->next = list2;
        list2->next = list1Next;
        list1 = list2;
        list2 = list2Next;
    }
    return head;
}

inline ListNode* impl(vector<ListNode*>& lists, int from, int to) {
    if (from == to) {
        return nullptr;
    }
    if (from + 1 == to) {
        return lists[from];
    }

    int mid = (to + from) / 2;
    return mergeTwo(impl(lists, from, mid), impl(lists, mid, to));
}

inline ListNode* mergeKLists(vector<ListNode*>& lists) {
    return impl(lists, 0, lists.size());
}