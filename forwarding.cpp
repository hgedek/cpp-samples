#include <iostream>
#include <functional>


void foo(int& ) { std::cout << "lvalue" << std::endl; }
void foo(const int&) { std::cout << "const lvalue" << std::endl; }
void foo(int&& ) { std::cout << "rvalue" << std::endl; }

template <class T>
void forward(T&& value) {
    foo(std::forward<T>(value));
}

template <class T>
void non_forward(T&& value) {
    foo(value);
}


// && => & or && 
// T&& => T& or T&& or const T&

int main() {

    int a = 0;
    const int b = 0;

    forward(std::ref(a)); // T
    forward(std::ref(b)); // const T
    forward(0); // rvalue


    non_forward(a); // T& 
    non_forward(b); // const T&
    non_forward(0); // T& !!!!!!!!! ERROR !!!!!!!!!! => this is temp but it accted as lvalue


    // std::forward<> => is best for template programming to move to correct typed target
}
