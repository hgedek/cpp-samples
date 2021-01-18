#include <iostream>

struct A {
    A() = default;
    A(const A&) {
        std::cout << "cctor" << std::endl;
    }
};

auto get(const A& a) {
    std::cout << "get" << std::endl;
    std::cout << typeid(a).name() << std::endl;
    return a;
}

int main() {
    
    A a;


    // copy_ellison not works
    // cctor will be called
    // parameter type is const& so we should keep const T& too
    auto const& ret = get(a);
    std::cout << typeid(ret).name() << std::endl;

    return 0;
}
