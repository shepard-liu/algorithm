#include "207_course_schedule.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef std::tuple<vector<vector<int>>, int, bool> TestCase;

void test_course_schedule(TestCase& c) {}

TEST(leetcode, course_schedule) {
    std::vector<TestCase> cases{};

    for (TestCase& c : cases) {
        test_course_schedule(c);
    }
}
