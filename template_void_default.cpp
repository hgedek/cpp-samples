#include <iostream>

template <class T, class U = void, class Z = void>
struct S{};

int main() {

    (void)S<int, int, int> {};
    (void)S<int, int> {};
    (void)S<int> {};
}
