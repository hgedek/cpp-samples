#include <iostream>

template <class T>
inline void checked_delete(T* ptr) {
    // if T is not defined till now this will not work so 
    // undefined T's not usable and will compile error
    char type_must_be_completed[sizeof(T) ? 1 : -1];
    (void)sizeof(type_must_be_completed);
    delete ptr;
}

template <class T>
struct checked_deletor: std::unary_function<T*, void> {
    void operator()(T* ptr) const {
        checked_delete(ptr);
    }
};

int main() {

    checked_deletor<int> D;

    int* ptr = new int(1);
    
    D(ptr);

    return 0;
}
