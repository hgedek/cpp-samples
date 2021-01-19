#include <iostream>
#include <type_traits>

template <class T, class = void>
struct has_foo: std::false_type{};

template <class T>
struct has_foo<T, std::void_t<decltype(std::declval<T>().foo())>>: std::true_type{};

struct A {
};

struct B {
    void foo() {}
};

int main() {

    if constexpr (has_foo<B>::value) 
        std::cout << "B has foo" << std::endl;

    if constexpr (has_foo<A>::value)
        std::cout << "A has foo" << std::endl;

}
