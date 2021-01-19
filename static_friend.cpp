#include <iostream>

struct base {
    virtual ~base() = default;
private:
    virtual void func(int) = 0;

    friend struct Attorney;
};

int foo() {
    return 0;
}

struct derived: public base {
    ~derived() = default;

private:
    virtual void func(int) {
        std::cout << "derived" << std::endl;
    }
};

struct Attorney {
private:
    // here & => means call by ref like pointer
    // so it triggers polymorphism
    // but friendship is not inherited at inheritance
    // so if we tried derived it will not allow
    // we re just using base & friendship while hiding its actually derived 
    static void callFunc(base& b, int x) {
        return b.func(x);
    }

    friend int main();
};

int main() {
    derived d;
    Attorney::callFunc(d, 10);
}
