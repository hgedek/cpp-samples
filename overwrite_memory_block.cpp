#include <iostream>

void foo(const char* data, size_t size) {}

struct S {
    int i;
    double d;
};

int main() {
    
    int i = 10;
    int* ptr = &i;

    std::cout << &i << ":" << ptr << std::endl;

    float* fptr = reinterpret_cast<float*>(&i);

    std::cout << fptr << std::endl;

    *fptr = 3.3f;

    std::cout << *fptr << ":" << i << std::endl;

    int* ii = new(fptr) int(10);

    std::cout << *ii << ":" << *fptr << std::endl;

    return 0;

}
