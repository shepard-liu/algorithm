#include "19_remove_nth_node_from_end_of_list.hpp"
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

void test_remove_nth_node_from_end_of_list(TestCase& c) {

}

TEST(leetcode, remove_nth_node_from_end_of_list) {
    std::vector<TestCase> cases{};

    for(TestCase& c:cases) {
        test_remove_nth_node_from_end_of_list(c);
    }
}

