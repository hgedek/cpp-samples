#include <iostream>
#include <numeric>
#include <algorithm>

template <class T>
struct Array {

    Array() = default;
    ~Array() = default;

    Array( const Array& other ) {
        std::copy(other.data, other.data + SIZE, data);
    }


    template <class U>
    Array( const Array<U>& other) {
        std::copy(other.data, other.data + SIZE, data);
    }

    enum { SIZE = 10 };

    T data[SIZE];
};


int main() {

    Array<int> a1;

    std::iota(a1.data, a1.data + Array<int>::SIZE, 0);

    Array<int> a3 = a1;

    Array<float> a2 = a1; 
}
