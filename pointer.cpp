#include <iostream>

void pointer_to_member() {
    
    struct S { unsigned m; };

    unsigned S::*ptr = &S::m;

    S s = {10};

    std::cout << s.*ptr << std::endl;

    S* sp = &s;
    sp->m = 1;

    std::cout << sp->*ptr << std::endl;
}


void base_derived_pointers() {
    
    struct Base { int m; };
    struct Derived: Base { };

    int Base::*ptr = &Base::m;
    int Derived::*ptr2 = &Derived::m;

    Derived d;
    d.m = 10;

    std::cout << d.*ptr << std::endl;
    std::cout << d.*ptr2 << std::endl;
}

void pointer_to_member_function() {
    
    struct S {
        void foo() {
            std::cout << "S::foo" << std::endl;
        }

        static void bar() {
            std::cout << "S::bar" << std::endl;
        }
        
        int m = 0;
    };

    int S::*p = &S::m;

    void (*SPtr)() = &S::bar;

    void (S::*Sptr2)() = &S::foo;

    S s;

    std::cout << s.*p << std::endl;

    (*SPtr)();

    (s.*Sptr2)();
}


int main() {

    pointer_to_member();
    base_derived_pointers();
    pointer_to_member_function();
}
