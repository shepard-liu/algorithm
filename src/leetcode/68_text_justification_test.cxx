#include "68_text_justification.hpp"

#include <string>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<string>, int> TestCase;

void test_text_justification(TestCase& c) {
    vector<string> ans = fullJustify(c.first, c.second);
    for (auto l : ans) {
        std::cout << "\"" << l << "\"" << std::endl;
    }
}

TEST(leetcode, text_justification) {
    std::vector<TestCase> cases{
        {{"This", "is", "an", "example", "of", "text", "justification."}, 16},
        {{"What", "must", "be", "acknowledgment", "shall", "be"}, 16},
        {{"Science", "is", "what", "we", "understand", "well", "enough", "to",
          "explain", "to", "a", "computer.", "Art", "is", "everything", "else",
          "we", "do"},
         20}};

    for (TestCase& c : cases) {
        test_text_justification(c);
    }
}
