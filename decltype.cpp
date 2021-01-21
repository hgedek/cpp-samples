#include <iostream>
#include <type_traits>

template <class T, class U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {

    int a = 10;
    decltype(a) b = 11;

    std::cout << "a and b re same type ? " << std::is_same_v<decltype(a), decltype(b)> << std::endl;


    auto f = [](int a, int b) -> int {
        return a*b;
    };

    decltype(f) f2 = f;

    std::cout << f2(2,3) << std::endl;

    return 0;
}
