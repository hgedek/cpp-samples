#include <iostream>

template <class T>
T PI = 3.14;

template <>
const char* PI<const char*> = "PI";

template <>
int PI<int> = 3;

int main() {

    std::cout << PI<float> << std::endl;

    std::cout << PI<const char*> << std::endl;

    std::cout << PI<int> << std::endl;


    return 0;

}
