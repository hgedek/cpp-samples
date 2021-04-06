#include <iostream>

template <class T>
struct S {
  void print() { std::cout << "first" << std:: endl; }
};

template <class T>
struct S<T[]> {
  void print() { std::cout << "second" << std::endl; }
};


int main() {
  S<int> {}.print();
  S<int[]> {}.print();
}
