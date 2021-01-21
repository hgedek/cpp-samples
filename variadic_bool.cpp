#include <iostream>


template <class T, class...Ts>
bool all_of(T t, Ts...ts) {
    return ( t && ... && ts );
}

template <class ...Ts>
bool all_of_V2(Ts...ts) {
    return  ((ts && true) && ...);
}

int main() {
}
