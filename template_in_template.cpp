#include <iostream>

template <typename> struct S;
template <typename T> struct S<T*>;

template <class T>
struct B {
    friend S<T>;
    friend S<T*>;

    void set(int val) { value = val; }
private:
    int value;
};


template <class T>
struct S {
    S(B<T>* p): ptr(p){}

    void print() const { std::cout << ptr->value << std::endl; }
private:
    B<T>* ptr;
};

int main() {
    B<int> b;
    b.set(10);

    S<int> s(&b);
    s.print();

    return 0;
}
