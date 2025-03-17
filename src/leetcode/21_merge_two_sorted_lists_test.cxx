#include "21_merge_two_sorted_lists.hpp"

#include <vector>

#include "../test_utils.hpp"

typedef int TestCase;

void test_merge_two_sorted_lists(TestCase& c) {}

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

TEST(leetcode, merge_two_sorted_lists) {
    ListNode* t = new ListNode;
    t->val = 1;
    t->next = new ListNode;
    t->next->val = 2;
    std::cout << t;
    std::vector<TestCase> cases{};

    for (TestCase& c : cases) {
        test_merge_two_sorted_lists(c);
    }
}
