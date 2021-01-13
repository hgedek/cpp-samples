#include <iostream>
#include <memory>

template <class T>
struct Ptr {

    T* pad;
    T* data;

    Ptr(T* arg): pad(nullptr), data(arg) {
        std::cout << "ctor: " << this << std::endl;
    }

    ~Ptr() {
        delete data; //ownership
    }

    T** operator&() { return &data; }
};

template <class T>
void foo(Ptr<T>* ptr) {
    std::cout << "ptr overload called: " << ptr << std::endl;
}

void foo(int** ptr) {
    std::cout << "int** called" << std::endl;
}

int main() {
    Ptr<int> ptr (new int(100));
    foo(&ptr); // call of operator&
    foo(std::addressof(ptr)); // no call for operator& => on the flight parsing Ptr<T> to &Ptr<T> and => Ptr<T>*
}
