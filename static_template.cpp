#include <iostream>

struct S {
    static void Foo() {
        std::cout << "Foo" << std::endl;
    }

    template <class T>
    static void bar(T&& value) {
        std::cout << value << std::endl;
        std::cout << typeid(value).name() << std::endl;
        value = T();
    }
};

int main() {

    S::Foo();
    S::bar(0);
    S::bar(1.1f);
    S::bar(3.0);
}

