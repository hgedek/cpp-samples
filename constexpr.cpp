#include <iostream>
#include <iostream>

struct S {
    
    union {
            struct {
                        int a, b, c;
                    };
            
            int arr[3];
        };
    
    constexpr S( int x, int y , int z ): a(x), b(y), c(z) {}
       
       constexpr unsigned size() const { return arr[0] * arr[1] * arr[2]; }
};

constexpr auto value = 0; // internal linkage & inline
constexpr float fvalue = 0.0f;

struct Rectangle {

    static constexpr auto SIZE = 10;

    uint32_t w;
    uint32_t h;

    constexpr Rectangle(uint32_t width, uint32_t height): w(width), h(height){}

    constexpr auto size() const { return w * h; }
};

int main() {

    constexpr auto R = Rectangle{2,2};

    static_assert(R.size() == 4, "ups");

    constexpr auto s = S(2,3,4);
    
    std::cout << s.size() << std::endl;
}
