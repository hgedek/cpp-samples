#include <iostream>

int main() {
    
    int a = 0, b = 0, c = 0;

    auto l = [a, &b, &c]() mutable {
        a = 1;
        b = 2;
        c = 3;
    };

    std::cout << a << b << c << std::endl;

    l();

    // you can assing readonly variable inside of lambda with mutable but this doesnt
    // change outside values
    std::cout << a << b << c << std::endl;


    auto l2 = [&temp = a]() {
        temp = -1;
    };

    l2();
   
   // referencing a variable will effect its value 
    std::cout << a << std::endl;
}
