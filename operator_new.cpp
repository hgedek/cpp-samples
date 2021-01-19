#include <new>
#include <cstdlib>
#include <iostream>

struct S {

    void* operator new(std::size_t size) {
        return ::operator new(size);
    }

    void operator delete(void* ptr) {
        ::operator delete(ptr); 
    }

    int value;
};

struct SS {
    void* operator new(std::size_t) = delete;
};

int main() {

    S* s = new S();
    s->value = 10;
    std::cout << s->value << std::endl; 
    delete s;

//    SS* ss = new SS();

    return 0;
}
