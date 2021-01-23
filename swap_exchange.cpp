#include <vector>
#include <array>
#include <iostream>

struct S {
    int value;

    S() = default;
    S(int v): value(v) {}
    S(const S& other) { std::cout << "cctor" << std::endl; value = other.value; }
    S& operator=(const S & other) = default;
    S(S&& other) { std::cout << "mvtor" << std::endl; std::swap(value, other.value); }
    S& operator=(S&&) = default;
};

int main() {


    int a = 0;

    std::cout << std::exchange(a, -1) << std::endl;
    std::cout << a << std::endl;


    std::vector<int> v;

    std::exchange(v, {1,2,3,4,5});

    S s;
    
    auto old_s = std::exchange(s, -1);
    std::cout << old_s.value << std::endl;
    std::cout << s.value << std::endl;

}
