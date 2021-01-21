#include <iostream>

template <class T>
struct S {
    static constexpr auto value = 0;
};

template <class T>
struct S<T*> {
    static constexpr auto value = 1;
};

template <class T>
struct S<T&> {
    static constexpr auto value = 2;
};

template <class T>
struct S<T&&> {
    static constexpr auto value = 3;
};

template <class T>
struct S<const T&> {
    static constexpr auto value = 4;
};

int main() {
    std::cout << S<int>::value << std::endl;
    std::cout << S<int&>::value << std::endl;
    std::cout << S<int&&>::value << std::endl;
    std::cout << S<int*>::value << std::endl;
    std::cout << S<const int&>::value << std::endl;
}
