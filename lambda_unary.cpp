#include <iostream>

int main() {

    auto l1 = +[]{};
    auto l2 = *[]{};
    auto l3 = []{};

    std::cout << typeid(l1).name() << std::endl;
    std::cout << typeid(l2).name() << std::endl;
    std::cout << typeid(l3).name() << std::endl;
}
