#include <iostream>
#include <iomanip>
#include <any>
#include <vector>
#include <string>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <functional>

template <class T, class U>
const T to(const U& op);

template <class T, class U>
const T* to(const U* op);


template <class T, class F>
inline std::pair<const std::type_index, 
                 std::function<void(std::any const&)>>
        to_any_visitor(F const& f) {
        
        return {
            std::type_index(typeid(T)),
            [f](std::any const& p) {
                if constexpr (std::is_void_v<T>)
                    f();
                else
                    f(std::any_cast<const T&>(p));
            } 
        };
}

static std::unordered_map<std::type_index, std::function<void(std::any const&)>>
visitors {
    to_any_visitor<void>([](void){std::cout << "void" << std::endl; }),
    to_any_visitor<int>([](const int& p){ std::cout << "int:" << p << std::endl; }),
    to_any_visitor<float>([](const float& f) { std::cout << "float:" << f << std::endl; }),
    to_any_visitor<const char*>([](const char* ptr) { std::cout << std::quoted(ptr) << std::endl; })
};

template <class T>
inline void print(const T& param) { std::cout << param << std::endl; }

int main() {

    using namespace std::literals;

    std::vector<std::any> v;

    v.push_back(std::make_any<int>(0));
    v.push_back(2.2f);
    v.push_back({"test"s});

    for (const auto& p: v) {
        if (p.type() == typeid(int)){ std::cout << std::any_cast<int>(p) << std::endl; }
        else if(p.type() == typeid(float)){ std::cout << std::any_cast<float>(p) << std::endl; }
        else if(p.type() == typeid(std::string)){ std::cout << std::any_cast<std::string>(p) << std::endl; }
        else 
            throw std::bad_any_cast();
    }

    
    std::any i = std::make_any<int>(1);
    
    const int* ptr = std::any_cast<int>(&i);
    std::cout << *ptr << std::endl;


    std::any a1 = 0;
    std::any a2 = 0.1f;
    std::any a3 = "test";


    // types are very important
    // T != T&
    // T != const T&... so while casting being carefull in c++ is very important
    print(std::any_cast<const int&>(a1));
    print(std::any_cast<const float&>(a2));
    print(std::any_cast<const char*&>(a3));

    visitors[typeid(int)](a1);
    visitors[typeid(float)](a2);
    visitors[typeid(const char*)](a3);

    return 0;
}
