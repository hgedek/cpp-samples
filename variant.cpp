#include <iostream>
#include <variant>
#include <any>
#include <optional>
#include <vector>

void print(int) { std::cout << "int" << std::endl; }
void print(double) { std::cout << "double" << std::endl; }


int main() {

    using variant_t = std::variant<int,double>;

    std::vector<variant_t> v;

    v.emplace_back(1);
    v.emplace_back(1.2);

    for (auto& x : v)
        if (std::holds_alternative<int>(x))
            print(std::get<int>(x));
        else if(std::holds_alternative<double>(x))
            print(std::get<double>(x));

    return 0;
}
