#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

inline std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
    os << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];

        if (i != vec.size() - 1) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

inline std::ostream &operator<<(std::ostream &os,
                                const std::vector<double> &vec) {
    os << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];

        if (i != vec.size() - 1) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

inline std::ostream &operator<<(std::ostream &os,
                                const std::vector<std::vector<int>> &vec) {
    os << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];

        if (i != vec.size() - 1) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

inline std::ostream &operator<<(std::ostream &os,
                                const std::vector<std::string> &strs) {
    os << "[";

    for (std::size_t i = 0; i < strs.size(); ++i) {
        os << strs[i];

        if (i != strs.size() - 1) {
            os << ", ";
        }
    }
    os << "]";

    return os;
}

inline std::ostream &operator<<(
    std::ostream &os, const std::vector<std::vector<std::string>> &strs) {
    os << "[";

    for (std::size_t i = 0; i < strs.size(); ++i) {
        os << strs[i];

        if (i != strs.size() - 1) {
            os << ", ";
        }
    }
    os << "]";

    return os;
}

/**
 * @brief Generator uniformly distributed random integers.
 *
 * @param size
 * @param seed default: 0
 * @param from default: 0
 * @param to default: 10
 * @return std::vector<int>
 */
inline std::vector<int> random_int_array(size_t size, size_t seed = 0,
                                         int from = 0, int to = 10) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib_int(from, to);

    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = distrib_int(gen);
    }

    return arr;
}

typedef void (*Sort_func)(std::vector<int> &);

inline void test_sorting_algorithm(Sort_func func, std::size_t seed,
                                   std::size_t size = 10,
                                   bool verbose = false) {
    std::stringstream ss;
    std::vector<int> array = random_int_array(size, seed, 0, size);

    ss << "Case(" << seed << "): " << array << "\n";

    std::vector<int> expected(array);

    func(array);

    std::sort(expected.begin(), expected.end(),
              [](const int &a, const int &b) { return a < b; });

    bool is_equal = std::equal(array.begin(), array.end(), expected.begin(),
                               expected.end());

    ss << "Got: " << array << "\n"
       << "Expected: " << expected;

    EXPECT_TRUE(is_equal) << ss.str();
    if (verbose) {
        std::cout << ss.str() << std::endl;
    }
}

const std::vector<uint64_t> primes{
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
    53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
    199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
    383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

inline std::string random_alphabet_string(size_t seed = 0, size_t size = 15) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib_int(0, 25);

    std::string str(size, 0);
    for (auto &c : str) {
        c = char(distrib_int(gen) + 65);
    }

    return str;
}

inline std::string random_substring(const std::string &str, size_t seed = 0) {
    std::mt19937 gen(seed);

    std::uniform_int_distribution<> distrib_start_pos(0, str.size());
    size_t start_pos = distrib_start_pos(gen);

    std::uniform_int_distribution<> distrib_substr_size(0,
                                                        str.size() - start_pos);
    size_t substr_size = distrib_substr_size(gen);

    return str.substr(start_pos, substr_size);
}

typedef size_t (*String_matching_func)(const std::string &str,
                                       const std::string &substr);

inline void test_string_matching_algorithm(String_matching_func func,
                                           const std::string &str,
                                           const std::string &substr) {
    EXPECT_EQ(func(str, substr), str.find(substr))
        << "Case: \"" << str << "\" @ \"" << substr << "\""
        << "\n";
}

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

inline void visualize_tree(const std::string &out_path,
                           const std::vector<int> &bin_tree) {
    std::filesystem::path path(out_path);
    std::ofstream ofs(path.replace_extension(".dot"));

    if (!ofs.is_open()) {
        throw std::runtime_error("Cannot open output path \"" + out_path +
                                 "\"");
    }

    ofs << "digraph Tree {\n";
    ofs << "node [shape=circle, style=filled, fillcolor=lightblue];\n";

    int n = bin_tree.size();

    for (int i = 0; i < n; ++i) {
        ofs << "N_" << i << " [label=\"" << bin_tree[i] << "\"];";
    }

    for (int i = 0; i < n; ++i) {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        if (lc < n) {
            ofs << "N_" << i << " -> "
                << "N_" << lc << ";";
        }
        if (rc < n) {
            ofs << "N_" << i << " -> "
                << "N_" << rc << ";";
        }
    }

    ofs << "}\n";
    ofs.close();

    system(("dot -Tpng " + path.replace_extension(".dot").string() + " -o " +
            path.replace_extension(".png").string())
               .c_str());
}
