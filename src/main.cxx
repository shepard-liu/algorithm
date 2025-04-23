#include <chrono>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::string> split(const std::string& str,
                               const std::string& delim) {
    if (str.size() <= delim.size()) {
        return {};
    }
    std::vector<std::string> res;

    size_t lastPos = 0;
    do {
        auto pos = str.find(delim, lastPos);
        if (pos != std::string::npos) {
            res.push_back(str.substr(lastPos, pos - lastPos));
        } else {
            break;
        }
        lastPos = pos + delim.size();
    } while (true);

    if (lastPos < str.size()) {
        res.push_back(str.substr(lastPos));
    }

    return res;
}

void trim(std::string& str) {
    if (str.size() == 0) {
        return;
    }
    int s = 0, e = str.size() - 1;

    while (s < str.size() && str[s] == ' ') {
        s++;
    }

    while (e >= 0 && str[e] == ' ') {
        e--;
    }

    if (e <= s) {
        str = "";
        return;
    }
    str = str.substr(s, e - s + 1);
}

struct UnionFind {
    std::vector<std::pair<int, int>> data;
    std::vector<int> ranks{};
    std::unordered_map<int, int> lookup;

    void makeSet(int key, int val) {
        lookup[key] = data.size();
        ranks.push_back(1);
        data.push_back({data.size(), val});
    }

    int find(int idx) {
        if (data[idx].first != idx) {
            data[idx].first = find(data[idx].first);
        }
        return data[idx].first;
    }

    void mergeSet(int s1, int s2) {
        int p1 = find(s1);
        int p2 = find(s2);

        if (p1 == p2) {
            return;
        }

        if (ranks[p1] < ranks[p2]) {
            data[p2].first = p1;
        } else if (ranks[p1] > ranks[p2]) {
            data[p1].first = p2;
        } else {
            data[p1].first = p2;
            ranks[p2]++;
        }
    }

    int get(int key) { return data[getIndex(key)].second; }

    int getIndex(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return -1;
        }
        return it->second;
    }

    std::vector<std::vector<int>> dump() {
        std::vector<std::vector<int>> groups;
        std::unordered_map<int, int> map;
        for (int i = 0; i < data.size(); ++i) {
            auto root = find(data[i].first);
            auto it = map.try_emplace(root, groups.size());
            if (it.second == true) {
                groups.push_back({});
            }
            groups[it.first->second].push_back(data[i].second);
        }

        return groups;
    }
};

int main() {
    auto time = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(time);
    std::tm* nowTm = std::localtime(&nowTime);
    std::stringstream ss;
    ss << std::put_time(nowTm, "%Y-%m-%d %H:%M:%S");
    auto timeStr = ss.str();

    int* ptr = nullptr;
    *ptr = 100;
}