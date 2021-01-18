#include <iostream>

template <class T>
struct S {

    S(T&& value): value(std::move(value)) {}

    T value;
};

template <class T>
S(T const&) -> S<T>;

int main() {
    S<int> s {10};
}
