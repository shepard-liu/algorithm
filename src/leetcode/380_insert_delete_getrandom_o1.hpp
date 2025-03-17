// https://leetcode.cn/problems/insert-delete-getrandom-o1/ Insert Delete
// GetRandom O(1)
#include <cstddef>
#include <cstdint>
#include <random>
#include <utility>
#include <vector>
using namespace std;

class RandomizedSet {
    std::vector<int> data;
    std::vector<bool> flags;
    size_t numElement = 0;

    const size_t SizeMultiplier{4};
    const size_t InitialSize{4};
    const double LoadFactor{0.6};

    const size_t HashPrime = 0x9E3779B9;

    std::mt19937_64 gen{};
    std::uniform_int_distribution<size_t> dist{};

    size_t hash(int val) {
        return (((val * HashPrime) ^ (val >> 16)) & 0xFFFFFFFF) %
               data.capacity();
    }

    size_t probe(size_t h, size_t i) {
        return ((2 * h + i + i * i) / 2) % data.capacity();
    }

    void migrate() {
        std::vector<int> oldData(std::move(data));
        std::vector<bool> oldFlags(std::move(flags));
        data = std::vector<int>(oldData.size() * SizeMultiplier, 0);
        flags = std::vector<bool>(oldFlags.size() * SizeMultiplier, false);
        numElement = 0;

        for (size_t i = 0; i < oldData.size(); ++i) {
            if (oldFlags[i] == true) {
                insert(oldData[i]);
            }
        }
    }

   public:
    RandomizedSet() : gen(0) {
        data = std::vector<int>(InitialSize, 0);
        flags = std::vector<bool>(InitialSize, false);
        dist = std::uniform_int_distribution<size_t>(0, InitialSize - 1);
    }

    bool insert(int val) {
        for (size_t i = 0; i < data.size(); ++i) {
            size_t pos = probe(hash(val), i);
            if (flags[pos]) {
                if (data[pos] == val) {
                    return false;
                }
                continue;
            }
            data[pos] = val;
            flags[pos] = true;
            numElement++;
            break;
        }

        if (numElement / double(data.size()) >= LoadFactor) {
            migrate();
        }

        return true;
    }

    bool remove(int val) {
        for (size_t i = 0; i < data.size(); ++i) {
            size_t pos = probe(hash(val), i);
            if (flags[pos] == true) {
                if (data[pos] == val) {
                    flags[pos] = false;
                    numElement--;
                    return true;
                }
                continue;
            }
            return false;
        }
        return false;
    }

    int getRandom() {
        size_t rand = dist(gen);
        for (size_t i = 0; i < data.size(); ++i) {
            size_t pos = probe(rand, i);
            if (flags[pos] == true) {
                return data[pos];
            }
        }
        return 0;
    }
};