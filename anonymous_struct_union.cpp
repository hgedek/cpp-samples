#include <iostream>


// normal
struct S {
    int a;
    int b;
    char c;
};

union U {
    char c;
    int a;
};

// anonymous
struct SS {
    struct {
        int a;
        int b;
        char c;
    };

    union {
        char cc;
        int aa;
    };
};

int main() {
    SS ss;
    ss.a = 0;
    ss.b = 1;
    ss.c = 'c';

    ss.aa = 0;

}

