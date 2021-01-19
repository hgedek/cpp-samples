#include <iostream>

// a general class
// template type and its also base class
// we try to access base class members inside of worker
// policy will response our questions like necessary information
// metaprogramming is nice here because it allows compile time type generation so dynamic

template <class T>
struct Printer: private T {
    void print() {
        auto width = T::get_width();
        auto color = T::get_color();
        auto font = T::get_font();

        (void)width;
        (void)color;
        (void)font;
        std::cout << "printing" << std::endl;
    }
};


struct Arial{
    constexpr const char* get_font() const { return "arial"; }
    constexpr const char* get_color() const { return "red";  }
    constexpr int get_width() const { return 10; }
};


struct Times {
    constexpr const char* get_font() const { return "times"; }
    constexpr const char* get_color() const { return "black"; }
    constexpr int get_width() const { return 11; }
};

int main() {

    Printer<Arial> p;
    Printer<Times> t;

    p.print();
    t.print();
}
