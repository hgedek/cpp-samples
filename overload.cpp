#include <variant>
#include <iostream>

template <class ...Ts>
struct overload: Ts... {
    using Ts::operator()...;
};


template <class...Ts>
overload(Ts...) -> overload<Ts...>;

int main() {

    std::variant<int, float, double> v{1.2f};

    std::visit (overload{
            [](int){ std::cout << "int";},
            [](float) {std::cout << "float"; },
            [](double) {std::cout << "double"; }}, v);


    std::cout << std::endl;

}
