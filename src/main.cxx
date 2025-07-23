#include <algorithm>
#include <boost/iterator/function_output_iterator.hpp>
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
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

struct base {
    using st = int;
};

template <typename T>
struct Tp {};

template <typename T>
struct A {
    using SomeType = T;
};

template <typename T>
struct B {};

template <typename D>
struct B<Tp<D>> : public A<Tp<D>> {
    using K = SomeType::st;
};

int main() {
    B<int>::SomeType a = 42;
    std::cout << "B<int>::SomeType: " << a << std::endl;
}
