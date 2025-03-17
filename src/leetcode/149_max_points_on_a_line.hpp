// https://leetcode.cn/problems/max-points-on-a-line/ Max Points on a Line
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

typedef tuple<int, int, int, int> Line;

struct Hash {
    size_t operator()(const Line& l) const {
        return (get<0>(l) << 24) ^ (get<1>(l) << 16) ^ (get<2>(l) << 8) ^
               (get<3>(l) << 4);
    }
};

inline int maxPoints(vector<vector<int>>& points) {
    if (points.size() == 1) {
        return 1;
    }

    unordered_map<Line, int, Hash> lines;

    int n = points.size();
    int maxPts{0};
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto& pt1 = points[i];
            auto& pt2 = points[j];
            int x1 = pt1[0], y1 = pt1[1];
            int x2 = pt2[0], y2 = pt2[1];
            int a{}, b{}, c{}, d{};
            if (x1 == x2) {
                a = 0;
                b = 1;
                c = 1;
                d = x1;
            } else if (y1 == y2) {
                a = 1;
                b = 0;
                c = 1;
                d = y1;
            } else {
                a = x1 - x2;
                b = y1 - y2;
                int g1 = std::gcd(a, b);
                a /= g1;
                b /= g1;

                if ((a * b < 0 && b < 0) || (a < 0 && b < 0)) {
                    a = -a;
                    b = -b;
                }

                c = a;
                d = y1 * a - b * x1;
                int g2 = std::gcd(d, c);
                c /= g2;
                d /= g2;

                if ((c * d < 0 && d < 0) || (c < 0 && d < 0)) {
                    c = -c;
                    d = -d;
                }
            }

            auto key = make_tuple(a, b, c, d);
            auto it = lines.try_emplace(key, 0);
            it.first->second++;
            maxPts = max(maxPts, it.first->second);
            std::cout << "pair (" << x1 << ", " << y1 << ") (" << x2 << ", "
                      << y2 << "): k = "
                      << (a == 0 ? "Inf" : std::to_string(double(b) / a))
                      << "; c = " << double(d) / c << "; (" << a << ", " << b
                      << ", " << c << ", " << d << "); "

                      << "; count = " << it.first->second << std::endl;
        }
    }
    return (1 + sqrt(1 + 8 * maxPts)) / 2;
}