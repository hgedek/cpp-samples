#include <iostream>


template <size_t N>
struct Arg {
    template <class T, class ...Ts>
        constexpr auto operator()(T t, Ts...ts) {
            return Arg<N-1>{}(ts...);
        }
};

template <>
struct Arg<0> {
    template <class T, class ...Ts>
        constexpr auto operator()(T t, Ts...){
            return t;
        }
};

int main() {
    std::cout << Arg<4>{}(0,1,2,3,4,5,6,6) << std::endl;
}
