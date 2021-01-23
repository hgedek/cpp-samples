#include <iostream>
#include <variant>
#include <any>
#include <optional>
#include <vector>


// methods
//
// index
//
// emplace
//
// others:
//
// holds_alternative
//
// get<>
// get_if<>
//
// visit

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


    std::variant<int,float,const char*> data;
    data = 0;

    if (std::holds_alternative<float>(data))
        std::cout << std::get<float>(data) << std::endl;


    if (std::holds_alternative<const char*>(data))
        std::cout << std::get<const char*>(data) << std::endl;

    if (auto ptr = std::get_if<int>(&data))
        std::cout << *ptr << std::endl;

    if (auto ptr = std::get_if<float>(&data))
        std::cout << *ptr << std::endl;


    auto value = std::get<int>(data);
    std::cout << value << std::endl;

    value = std::get<0>(data);
    std::cout << value << std::endl;

    return 0;
}
