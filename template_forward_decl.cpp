#include <iostream>

template <class T>
struct B {
    int value;

    template <class U>
    friend struct C;
};

template <class T>
struct C {
    void print(const B<T>& b){
        std::cout << b.value << std::endl;
    }
};

int main() {

    B<int> b = {1};
    C<int> c;
    c.print(b);

    return 0;
}

