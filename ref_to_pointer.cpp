#include <iostream>

void pass_by_value(int* ptr) {
    ptr = new int(10);
}

void pass_by_reference(int*& ptr) {
    ptr = new int(10);
}

void update_data(int* ptr) {
    *ptr = *ptr - 1;
}

void readonly_data(const int* ptr) {
    // *ptr = *ptr - 1;
}

void readonly_ptr( int* const ptr) {
    // ptr = new int(10);
}

void readonly_data_ptr(const int* const ptr) {
    // *ptr = 10;
    // ptr = new int(10);
}

int main() {
    int* ptr = new int(0);
    std::cout << *ptr << std::endl;

    pass_by_value(ptr);
    std::cout << *ptr << std::endl;

    pass_by_reference(ptr);
    std::cout << *ptr << std::endl;
}
