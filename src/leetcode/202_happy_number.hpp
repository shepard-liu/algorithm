// https://leetcode.cn/problems/happy-number/ Happy Number
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline bool isHappy(int n) {
    unordered_set<int> presences;
    while (true) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1) {
            return true;
        }
        if (presences.find(sum) != presences.end()) {
            return false;
        }

        presences.insert(sum);
        n = sum;
    }
    return false;
}