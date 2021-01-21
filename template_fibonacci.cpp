#include <iostream>

template <size_t N>
struct Fibbonacci {
    enum { Value = N * Fibbonacci<N-1>::Value };
};

template <>
struct Fibbonacci<0> {
    enum { Value = 1 };
};

int main() {
    constexpr auto value = Fibbonacci<10>::Value;
    std::cout << value << std::endl;
}
