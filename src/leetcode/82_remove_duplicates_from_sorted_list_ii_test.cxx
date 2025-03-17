#include "82_remove_duplicates_from_sorted_list_ii.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

#include "../test_utils.hpp"

inline std::ostream& operator<<(std::ostream& os, const ListNode* list) {
    os << '[';

    while (list != nullptr) {
        os << list->val;
        list = list->next;
        if (list != nullptr) {
            os << ", ";
        }
    }

    os << ']';
    return os;
};

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

typedef std::vector<int> TestCase;

void test_remove_duplicates_from_sorted_list_ii(TestCase& c) {
    auto head = listFromArray(c);
    auto myAns = arrayFromList(deleteDuplicates(head));
    std::vector<int> counts(100, 0);
    for (auto val : c) {
        counts[val]++;
    }
    std::vector<int> ans{};
    for (size_t i = 0; i < counts.size(); ++i) {
        if (counts[i] == 1) {
            ans.push_back(i);
        }
    }
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, remove_duplicates_from_sorted_list_ii) {
    std::vector<TestCase> cases{
        {1, 2, 3, 3, 4, 4, 5}, {}, {1}, {1, 1, 1}, {1, 5, 5, 5},
        {1, 2, 4, 4, 4}};

    for (TestCase& c : cases) {
        test_remove_duplicates_from_sorted_list_ii(c);
    }
}
