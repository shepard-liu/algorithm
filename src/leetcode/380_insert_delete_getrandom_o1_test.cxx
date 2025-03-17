#include "380_insert_delete_getrandom_o1.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef int TestCase;

TEST(leetcode, insert_delete_getrandom_o1) {
    RandomizedSet randomizedSet;
    randomizedSet.insert(
        1);  // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    randomizedSet.remove(2);  // 返回 false ，表示集合中不存在 2 。
    randomizedSet.insert(
        2);  // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    randomizedSet.getRandom();  // getRandom 应随机返回 1 或 2 。
    randomizedSet.remove(
        1);  // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    randomizedSet.insert(2);  // 2 已在集合中，所以返回 false 。
    int rand =
        randomizedSet
            .getRandom();  // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    ASSERT_EQ(rand, 2);
}
