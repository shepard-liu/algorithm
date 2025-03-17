#include "211_design_add_and_search_words_data_structure.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

void test_design_add_and_search_words_data_structure(TestCase& c) {}

void addWord(WordDictionary& d, string word) {
    std::cout << "AddWord: " << word << std::endl;
    d.addWord(word);
}

void searchWord(WordDictionary& d, string word) {
    std::cout << "SearchWord: " << word
              << (d.search(word) == true ? " = true" : "= false") << std::endl;
}

void perform(WordDictionary& d, vector<string>& ops,
             vector<vector<string>>& vals) {
    for (size_t i = 0; i < ops.size(); ++i) {
        string op = ops[i];
        string val = vals[i][0];
        if (op == "addWord") {
            addWord(d, val);
        } else {
            searchWord(d, val);
        }
    }
}

TEST(leetcode, design_add_and_search_words_data_structure) { WordDictionary d; }
