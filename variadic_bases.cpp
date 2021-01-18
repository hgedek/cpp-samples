#include <iostream>

template <class ...Ts>
struct S: Ts...{};
// redirecting params as base types
// forwarding template types from params
template <class ...Ts>
S(Ts...)->S<Ts...>;

struct A{};
struct B{};

int main() {

    // {} initializer a need here...you cant use normal !
    S{[]{}, [](int){}, [](int, float){}};
    S<A,B>{};
    S{A{},B{}};
    S<A>();
}
