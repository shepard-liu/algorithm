#include "92_reverse_linked_list_ii.hpp"
#include "../test_utils.hpp"
#include <vector>

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

typedef int TestCase;

void test_reverse_linked_list_ii(TestCase& c) {

}

TEST(leetcode, reverse_linked_list_ii) {
    std::vector<TestCase> cases{};

    for(TestCase& c:cases) {
        test_reverse_linked_list_ii(c);
    }
}

