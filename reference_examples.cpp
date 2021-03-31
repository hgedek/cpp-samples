#include <iostream>
#include <utility>
#include <functional>

void foo(int&) { std::cout << "lvalue" << std::endl; }
void foo(const int&) { std::cout << "const lvalue" << std::endl; }
void foo(int&&) { std::cout << "rvalue" << std::endl; }

int main() {

    int a = 0;

    foo(a); // lvalue
    foo(static_cast<const int>(a)); // rvalue - in the place value generation

    const int b = a;
    foo(b); // const lvalue

    foo(1); // rvalue
    
    foo(std::move(a)); // rvalue

    foo(int(a)); // rvalue

    int c = 0;

    foo(std::ref(c)); // lvalue
    foo(std::cref(c)); // const lvalue


    int& d = c; // aliasing
    foo(d); // lvalue


    return 0;

}
