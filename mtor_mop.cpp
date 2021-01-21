// if a class has 
// cctor | cop 
// then you have to define mtor & mop
//
// compiler will generate mtor & mop if you dont define cctor & cop
//

#include <iostream>
#include <string>
#include <iomanip>
#include <utility>

struct A {
    std::string s;
    int k;

    A(): s("test"), k(-1){}
    A(const A& a): s(a.s), k(a.k) { std::cout << "cctor" << std::endl; }
    A(A&& a): s(std::move(a.s)), k(std::exchange(a.k, -1)) { std::cout << "mvtor" << std::endl; }
};

struct B: A{

    std::string s2;
    int n;


    // implicit B()
    // implicit B(const B&)
    // implicit B(B&&)
    // calls A mtor
    // calls B mtor
};

struct C: B {
    C() = default;
    ~C() {} // dtor prevents implicit mvtor of C::C(C&&) !!!
    C(C const&) = default;
    C(C&&) = default; // you can force your way
};


int main() {

    A a1 = A();
    A a2 = std::move(a1); // mvtor called

    B b1 = B();
    std::cout << std::quoted(b1.s) << std::endl;
    B b2 = std::move(b1); //
    std::cout << std::quoted(b1.s) << std::endl;


    C c = C();
    C c2 = std::move(c); // calls mvtor


    return 0;

}
