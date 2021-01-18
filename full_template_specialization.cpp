#include <iostream>

template <class T>
struct is_void: std::false_type{};

template <>
struct is_void<void>: std::true_type{};

int main() {
    
    std::cout << is_void<int>::value << std::endl;
    std::cout << is_void<void>::value << std::endl;
}
