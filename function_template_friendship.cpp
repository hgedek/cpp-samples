#include <iostream>

template <class T>
struct Foo {
    Foo(T value): value(value) {}
    T value;

    friend std::ostream& operator<<(std::ostream& out , const Foo<T>& f) {
        out << f.value;
        return out;
    }
};


int main() {

    Foo<int> foo(1);

    std::cout << foo << std::endl;
}
