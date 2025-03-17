#include "86_partition_list.hpp"

#include <gtest/gtest.h>

#include <utility>
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

typedef std::pair<std::vector<int>, int> TestCase;

void test_partition_list(TestCase& c) {
    auto [vals, x] = c;
    auto list = listFromArray(vals);
    auto res = partition(list, x);
    std::vector<int> left{}, right{};
    for (auto v : vals) {
        if (v < x) {
            left.push_back(v);
        } else {
            right.push_back(v);
        }
    }
    left.insert(left.end(), right.begin(), right.end());

    auto myAns = arrayFromList(res);

    std::cout << vals << "; x = " << x << std::endl;

    EXPECT_EQ(myAns, left);
}

TEST(leetcode, partition_list) {
    std::vector<TestCase> cases{
        {{1, 4, 3, 2, 5, 2}, 3}, {{2, 1}, 2}, {{}, 0}, {{1}, 0}, {{0}, 1}};

    for (TestCase& c : cases) {
        test_partition_list(c);
    }
}
