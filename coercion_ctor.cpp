#include <iostream>
#include <memory>
#include <type_traits>

struct base{};
struct derived: base{};

template <class T>
class Ptr {
public:
    Ptr() = default;
    Ptr(const Ptr& other): ptr(other.ptr){
        std::cout << "cctor" << std::endl;
    }

    template <class U>
    Ptr(Ptr<U> const& other): ptr(other.ptr) {
        static_assert(std::is_base_of<T,U>::value, "convertion is not possible");
        std::cout << "coercing member template cctor" << std::endl;
    }

    Ptr& operator=(const Ptr& other) {
        ptr = other.ptr;
        std::cout << "ccop" << std::endl;
        return *this;
    }

    template <class U>
    Ptr& operator=(Ptr<U> const& other) {
        static_assert(std::is_base_of<T,U>::value, "convertion is not possible");
        ptr = other.ptr;
        std::cout << "other ccop" << std::endl;
        return *this;
    }

    T* ptr;
};

int main() {


    std::unique_ptr<base> ptr{new derived{}};

    Ptr<derived> p1;
    Ptr<base> b1 = p1;

    return 0;

}
