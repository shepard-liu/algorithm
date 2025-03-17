#include "148_sort_list.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "../test_utils.hpp"
typedef vector<int> TestCase;

ListNode* listFromArray(const std::vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* p{dummy};
    for (auto v : vals) {
        p->next = new ListNode(v);
        p = p->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

std::vector<int> arrayFromList(ListNode* head) {
    std::vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}

void test_sort_list(TestCase& c) {
    auto arr = c;
    auto list = listFromArray(arr);
    auto myList = sortList(list);
    auto myAns = arrayFromList(myList);
    std::sort(arr.begin(), arr.end());
    EXPECT_EQ(myAns, arr);
}

TEST(leetcode, sort_list) {
    std::vector<TestCase> cases{{5, 2, 6, 7, 3, 2, 1, 6, 7, 9}};

    for (TestCase& c : cases) {
        test_sort_list(c);
    }
}
