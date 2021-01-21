#include <iostream>

struct S {

    template <class T>
    void operator()(T const& value);

    template <class T>
    operator T() const { return T{}; }

    template <class T>
    bool operator!() const { return false; }

    template <class T>
    T* operator->()const { return this; }

    template <class T>
    T operator*() const { return T{}; }
};

int main() {}
