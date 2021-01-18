#include <iostream>
#include <stdexcept>

struct B {
    B() { throw std::runtime_error("B"); }
};

struct C {
    C() { throw std::runtime_error("C"); }
};

struct A {

    B _b;
    C _c;

    A() 
    try
        : _b(), _c(){}
    catch (std::runtime_error& e) {
    
        std::cout << e.what() << std::endl;
        throw;
    }

};

int main() {
    try {
        A a;
    }catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}

