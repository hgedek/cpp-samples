#include <iostream>

template <class T, class U>
struct One {
    using left = T;
    using right = U;
};

template <class A, class B, class C>
struct Two {
    using a = A;
    using b = B;
    using c = C;
};

int main() {
    
    One<int, float>::left l;
    One<int, double>::right r;

    std::cout << std::is_same<decltype(l), decltype(r)>::value << std::endl;
}
