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


    auto l3 = [count = 0]() mutable {
        int arr[] = {0,1,2,3,4,5,6};
        for (auto i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
            count++;
        return count;
    };

    std::cout << l3() << std::endl;
}
