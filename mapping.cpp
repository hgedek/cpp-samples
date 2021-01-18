#include <iostream>
#include <tuple>

int main() {

    const auto tpl = std::make_tuple(1, 1.1f, "sample");

    const auto [a,b,c] = tpl;

    std::cout << a << ":" << b << ":" << c << std::endl;

    return 0;
}
