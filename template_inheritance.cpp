#include <iostream>

template <class T, class U>
struct Holder: T, U {
    using T::operator();
    using U::operator();
};

struct A {
    void operator()(const A&) {
        std::cout << "A" << std::endl;
    }
};

struct B {
    void operator()(const B&) {
        std::cout << "B" << std::endl;
    }
};

template <class T>
struct Comparable {
    friend bool operator==(T const& l, T const& r) {
        return l.equal_to(r);
    }

    friend bool operator!=(T const& l, T const& r) {
        return !l.equal_to(r);
    }
};

struct User: private Comparable<User> {
    bool equal_to(const User& other) const {
        return id == other.id;
    }

    User(int id): id(id){}

    int id;
};


int main() {

    Holder<A,B> h;
    h(A());
    h(B());

    User u1 = {0};
    User u2 = {2};

    std::cout << (u1 == u2) << std::endl;


    return 0;
}
