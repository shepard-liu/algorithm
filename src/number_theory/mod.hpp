
#include <cstdint>

template <typename T>
inline T mod(T a, T b) {
    return (a % b + b) % b;
}