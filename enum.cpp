#include <iostream>

// unscoped enum
enum Color: int {
    red,
    blue,
    green
};

void foo(Color color) {
    switch (color) {
        case red:
            std::cout << "red" << std::endl;
            break;
        case blue:
            std::cout << "blue" << std::endl;
            break;
        case green:
            std::cout << "green" << std::endl;
            break;
    }
}

// scoped enum
enum struct Color2: int {
    red,
    blue,
    green
};

void bar(Color2 color) {
    switch (color) {
        case Color2::red:
            std::cout << "red" << std::endl;
            break;
        case Color2::blue:
            std::cout << "blue" << std::endl;
            break;
        case Color2::green:
            std::cout << "green" << std::endl;
            break;
    }
}

// creating own type

enum byte : unsigned char{};

enum INT : int {};
// char uchar int uint long ulong

enum uchar : unsigned char {};


enum class fruit { orange, apple };


int main() {

    foo(red);
    
    bar(Color2::red);

    uchar c = static_cast<uchar>(100);

    byte b = static_cast<byte>(10);

    INT i = static_cast<INT>(100);

    return 0;
}

