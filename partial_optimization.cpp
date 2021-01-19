#include <iostream>

template <bool, typename T = void>
struct enable{};

template <typename T>
struct enable<true, T> {
    using type = T;
};

int main() {
    return 0;
}
