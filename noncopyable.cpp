#include <iostream>

struct noncopyable {
protected:
    noncopyable() = default;
    ~noncopyable() = default;

private:
    noncopyable(noncopyable const&) = default;
    noncopyable& operator=(noncopyable const&)  = default;
};

struct object: noncopyable {
    object(){}
};

int main() {

    object o;

    // object o2 = o;
    // object o3; 
    // o3 = o;
}
