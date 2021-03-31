#include <iostream>

template <class T>
class Foo {
    T value;
public:
    Foo(const T& value): value(value) {}

    friend std::ostream& operator<<(std::ostream& out, const Foo& foo) {
        out << foo.value;
        return out;
    }
};

#ifndef __GNUC__
struct S;

template<class T> friend void bar(T const &, S const&);

struct S {
    int value;

    friend void bar<int>(int const& x, S const& s) {
        Foo<int> f( x + s.value) ;
        std::cout << f << std::endl; 
    }
};

int main() {

    S s = {2};
    bar(1, s);
}
#else 
int main() {
}
#endif
