#include <iostream>

struct base {
    void foo(int) { std::cout << "base::foo" << std::endl; }

protected:
    int m;
    using value_type = int;
};


struct derived: base {
    using base::m;
    using base::value_type;

    using base::foo;
};

using int_t = int;

int main() {
    int_t i = 0;

    derived d;
    d.foo(0);

    return 0;
}
