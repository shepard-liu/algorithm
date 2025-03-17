// https://leetcode.cn/problems/candy/ Candy
#include <cstddef>
#include <vector>
using namespace std;

inline int candy(vector<int>& ratings) {
    size_t n = ratings.size();
    if (n == 1) {
        return 1;
    }

    int sum = 0;
    size_t incLen = 0;
    int numValleys = 0;

    for (size_t i = 0; i < n; ++i) {
        int rLeft = i == 0 ? ratings[i] : ratings[i - 1];
        int rRight = i == n - 1 ? ratings[i] : ratings[i + 1];
        int r = ratings[i];

        // increasing
        if (r < rRight) {
            incLen++;
            // flat
        } else if (rLeft == r && r == rRight) {
            sum++;
            // increasing end
        } else if (rLeft < r && r == rRight) {
            incLen++;
            sum += (1 + incLen) * incLen / 2;
            incLen = 0;
            // peak or dec start
        } else if ((rLeft < r || rLeft == r) && r > rRight) {
            // find decreasing length
            size_t decStart = rLeft == r ? i : i + 1;
            size_t decLen = 0, nextIndex = 0;

            while (decStart + decLen < n) {
                int rl = (decStart + decLen) == 0
                             ? ratings[decStart + decLen]
                             : ratings[decStart + decLen - 1];
                int rr = (decStart + decLen == n - 1)
                             ? ratings[decStart + decLen]
                             : ratings[decStart + decLen + 1];
                int rc = ratings[decStart + decLen];

                // valley
                if (rl > rc && rc < rr) {
                    numValleys++;
                    decLen++;
                    nextIndex = decStart + decLen - 1;
                    break;
                    // dec end
                } else if (rl > rc && rc == rr) {
                    decLen++;
                    nextIndex = decStart + decLen;
                    break;
                    // decreasing or decreasing start
                } else if ((rl > rc || rl == rc) && rc > rr) {
                    decLen++;
                }
            }

            // peak
            if (rLeft < r) {
                int incSum = (1 + incLen) * incLen / 2;
                int decSum = (1 + decLen) * decLen / 2;
                sum += std::max(incLen, decLen) + 1 + incSum + decSum;
                // dec start
            } else if (rLeft == r) {
                sum += (1 + decLen) * decLen / 2;
            }
            incLen = 0;
            i = nextIndex - 1;
        }
    }

    sum -= numValleys;
    return sum;
}