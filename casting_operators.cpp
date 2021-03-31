#include <iostream>
#include <string>


struct A {
  int value;
};

struct B {
  int value;

  // group 1
  // ctors
  explicit B(int value): value(value) {}
  explicit B(std::string const& str): value(std::stoi(str)) {}
  B(const A& a): value(a.value) {}

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

  // group1
  B b = a;


  return 0;
}
