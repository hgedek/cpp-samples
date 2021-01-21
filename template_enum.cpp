#include <iostream>
#include <array>

template <int I>
struct Int2Type {
    enum { value = I };
};

template <class T, unsigned N>
class Array: public std::array<T,N> {
    enum AlgoType { NOOP, INSERTION_SORT, QUICK_SORT };

    static constexpr int algo = ( N == 0 ) ? NOOP : ( N < 50) ? INSERTION_SORT : QUICK_SORT;

    void sort(Int2Type<NOOP>) { std::cout << "Noop" << std::endl; }
    void sort(Int2Type<INSERTION_SORT>) { std::cout << "Insertion Sort" << std::endl; }
    void sort(Int2Type<QUICK_SORT>) { std::cout << "quick sort" << std::endl; }

public:
    void sort() {
        // tag: its common using tag as params in c++
        // using tags you overload functions 
        // std::piecewise_construct is an example
        sort(Int2Type<algo>{}); 
    }
};


int main() {

    Array<int, 10> a;
    a.sort();

    Array<int, 1000> a2;
    a2.sort();

}
