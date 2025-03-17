#include "138_copy_list_with_random_pointer.hpp"

#include <vector>

#include "../test_utils.hpp"

inline std::ostream& operator<<(std::ostream& os, const Trie* list) {
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

void test_copy_list_with_random_pointer(TestCase& c) {}

TEST(leetcode, copy_list_with_random_pointer) {
    std::vector<TestCase> cases{};

    for (TestCase& c : cases) {
        test_copy_list_with_random_pointer(c);
    }
}
