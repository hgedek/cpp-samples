#include <iostream>

template <size_t I>
struct Int2Type {

    static constexpr auto value = I;
    // enum { value = I };
    //
    using type = size_t;
    using current = Int2Type<I>;
    using next = Int2Type<I+1>;
    using prev = Int2Type<I-1>;
};

int main() {

    std::cout << Int2Type<5>::value << std::endl;
    std::cout << Int2Type<5>::next::value << std::endl;
    std::cout << Int2Type<5>::prev::value << std::endl;

}
