#include <iostream>

struct base {
    virtual base* clone() const {
        return new base(*this);
    }
};


struct derived: base {
    derived* clone() const override {
        return new derived(*this);
    }
};

int main() {
    
    base* b = base().clone();
    derived* d = derived().clone();

    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(d).name() << std::endl;

    return 0;
}
