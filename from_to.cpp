#include <iostream>

struct to_3 {

    double d;

    explicit to_3(double d): d(d){}

    explicit operator double() const { return d; }
};

struct to_2 {
    double d;

    explicit to_2(double d): d(d) {}

    explicit operator to_3() const { return to_3{d}; }
};

struct to_1 {
    double d;

    explicit to_1(double d): d(d) {}

    explicit operator to_2() const { return to_2{d}; }
};

struct from {

    double d;

    explicit from(double d): d(d) {}

    explicit operator to_1() const { return to_1{d}; }
};


int main() {


    from f{2.2};

    to_1 t1 = static_cast<to_1>(f);
    to_2 t2 = static_cast<to_2>(t1);
    to_3 t3 = static_cast<to_3>(t2);

    double d = static_cast<double>(t3);

    std::cout << d << std::endl;

}
