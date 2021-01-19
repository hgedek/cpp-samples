#include <iostream>

template <int... Ints>
struct Integers {
    static constexpr auto size = sizeof...(Ints);
};

int main() {
    
    std::cout << Integers<0,1,2,3>::size << std::endl;
    std::cout << Integers<0>::size << std::endl;

}
