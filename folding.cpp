#include <iostream>
#include <type_traits>
#include <string>

template <class ...Args>
auto all(Args&&... args) {
    return (args && ...);
}

template <class ...Args>
auto sum_generic(Args... args) {
    if constexpr ((std::is_same_v<std::string, Args> && ...)) {
        return (std::string{} + ... + args);
    } else {
        return (0 + ... + args);
    }
}

int main() {

    if (all(true, true, true)) std::cout << "true" << std::endl;

    std::cout << sum_generic(1,2,3,4) << std::endl;
}
