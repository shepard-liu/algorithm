#include <cstddef>
#include <string>
#include <utility>
#include <vector>

std::string random_alphabet_string(size_t seed = 0, size_t size = 15);

std::string random_substring(const std::string& str, size_t seed = 0);

typedef size_t (*String_matching_func)(const std::string& str,
                                       const std::string& substr);

void test_string_matching_algorithm(String_matching_func func,
                                    const std::string& str,
                                    const std::string& substr);

inline const std::vector<std::pair<std::string, std::string>>
    String_matching_test_cases{{"", ""},
                               {"", "jgun"},
                               {"datastructures", ""},
                               {"abcdefghij", "defg"},
                               {"helloworld", "world"},
                               {"stringsearch", "string"},
                               {"substringtest", "subring"},
                               {"algorithmic", "thmicx"},
                               {"patternmatching", "matach"},
                               {"performance", "form"},
                               {"complexityanalysis", "lexity"},
                               {"efficientcode", "coe"}};