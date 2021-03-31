#include <iostream>
#include <string>


struct A {
  int value;
};

struct B {
  int value;

  // group 1
  // ctors
  B(int value): value(value) {}
  B(std::string const& str): value(std::stoi(str)) {}
  B(A const& a): value(a.value) {}

  // group2
  // assignment operators
  B& operator=(int value) {
    this->value = value;
    return *this;
  }

  B& operator=(std::string const& str) {
    this->value = std::stoi(str);
    return *this;
  }

  B& operator=(const A& a) {
    this->value = a.value;
    return *this;
  }


  // group3
  // casting operators
  operator int() const { return value; }
  operator std::string() const { return std::to_string(value); }
  operator A() const { return A{value}; }
};

int main() {
 
  A a {10};

  using namespace std::literals::string_literals;

  // group1
  B b1 = a;
  B b2 = 0;
  B b3 = "0"s;

  // group 2
  b1 = a;
  b2 = 0;
  b3 = "0"s;

  //group 3
  a = b1;
  int x = b2;
  std::string s = b3;

  return 0;
}
