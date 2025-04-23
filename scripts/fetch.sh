#!/bin/bash

# 检查参数是否存在
if [ $# -eq 0 ]; then
    echo "Usage: $0 <question_id>"
    exit 1
fi

# 检查依赖工具
command -v jq >/dev/null 2>&1 || { echo "Error: jq is required but not installed."; exit 1; }
command -v curl >/dev/null 2>&1 || { echo "Error: curl is required but not installed."; exit 1; }

question_id=$1
api_url="https://leetcode.cn/api/problems/all"
problems_file="./scripts/data.json"

if [ ! -f "$problems_file" ]; then
    curl -s "$api_url" > "$problems_file"
fi

# 解析JSON数据
question_data=$(jq --arg qid "$question_id" '
    .stat_status_pairs[] | 
    .stat | 
    select(.question_id == ($qid | tonumber)) | 
    {title: .question__title, title_slug: .question__title_slug}
' "$problems_file")

echo "Question Data = " $question_data

# 检查是否找到题目
if [ -z "$question_data" ] || [ "$question_data" = "null" ]; then
    echo "Error: Question with ID $question_id not found"
    exit 1
fi

# 提取字段
title=$(jq -r '.title' <<< "$question_data")
title_slug=$(jq -r '.title_slug' <<< "$question_data")

# 生成合法标识符（基于title_slug）
sanitized_title=$(sed -e 's/-/_/g' \
                      -e 's/[^a-zA-Z0-9_]/_/g' \
                      -e 's/__\+/_/g' \
                      -e 's/^_//' \
                      -e 's/_$//' <<< "$title_slug")

# 处理数字开头的情况
[[ $sanitized_title =~ ^[0-9] ]] && sanitized_title="_$sanitized_title"

# 生成文件路径
src_dir="src/leetcode"
src_file="${src_dir}/${question_id}_${sanitized_title}.hpp"
test_file="${src_dir}/${question_id}_${sanitized_title}_test.cxx"

# 创建目录
mkdir -p "$src_dir"

# 创建源码文件
if [ ! -f "$src_file" ]; then
    echo "// https://leetcode.cn/problems/$title_slug/ $title" > "$src_file"
    echo "#include <vector>" >> "$src_file"
    echo "#include <string>" >> "$src_file"
    echo "using namespace std;" >> "$src_file"
    echo "Created source file: $src_file"
fi

# 创建测试文件
if [ ! -f "$test_file" ]; then
    cat << EOF > "$test_file"
#include "${question_id}_${sanitized_title}.hpp"
#include "../test_utils.hpp"
#include <vector>
typedef int TestCase;

void test_$sanitized_title(TestCase& c) {

}

TEST(leetcode, $sanitized_title) {
    std::vector<TestCase> cases{};

    for(TestCase& c:cases) {
        test_$sanitized_title(c);
    }
}

EOF
    echo "Created test file: $test_file"
fi

# 更新CMakeLists.txt
cmake_file="${src_dir}/CMakeLists.txt"
target_pattern="cxx_test(${sanitized_title} "

if [ ! -f "$cmake_file" ]; then
    echo "Error: CMakeLists.txt not found"
    exit 1
fi

if ! grep -qF "$target_pattern" "$cmake_file"; then
    echo "cxx_test(${sanitized_title} \"${question_id}_${sanitized_title}_test.cxx\")" >> "$cmake_file"
    echo "Updated CMakeLists.txt"
fi