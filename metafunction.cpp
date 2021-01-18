#include <iostream>

template <size_t N>
struct Factorial {
    // enum { value = N * Factorial<N-1>::value };
    static constexpr auto value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<0> {
    // enum { value = 1 };
    //
    static constexpr auto value = 1;
};

int main() {

    std::cout << Factorial<10>::value << std::endl;    

}
  
