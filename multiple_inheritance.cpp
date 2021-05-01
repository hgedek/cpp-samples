#include <iostream>

/* 
 *      A
 *    /   \
 *   B     C
 *    \   /
 *      D
 *      |
 *      E
 * */

struct A {
  A() {
    std::cout << "A" << std::endl;
  }
};

struct B: virtual A {
  B() {
    std::cout << "B" << std::endl;
  }
};

struct C: virtual A {
  C() {
    std::cout << "C" << std::endl;
  }
};

struct D: B, C {
  D() {
    std::cout << "D" << std::endl;
  }
};

struct E: D {
  E() {
    std::cout << "E" << std::endl;
  }
};

int main() {
  E e;
}

