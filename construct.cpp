#include <iostream>

template <class T, class U>
void construct(T& target, const U& value) {

    new (&target) U(value);
}

// new operator usage
// new(ptr) T(value); 
// we reuse a memory space for another

int main() {

    int x = 10;

    construct(x, 2.2f);

    std::cout << reinterpret_cast<float&>(x) << std::endl;
}

