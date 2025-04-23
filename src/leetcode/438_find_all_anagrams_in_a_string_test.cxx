#include "438_find_all_anagrams_in_a_string.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<string, string> TestCase;

void test_find_all_anagrams_in_a_string(TestCase& c) {
    auto [s, p] = c;
    auto myAns = findAnagrams(s, p);
    cout << myAns << endl;
}

TEST(leetcode, find_all_anagrams_in_a_string) {
    std::vector<TestCase> cases{{"cbaebabacd", "abc"}, {"abab", "ba"}};

    for (TestCase& c : cases) {
        test_find_all_anagrams_in_a_string(c);
    }
}
