// constexpr types are literal types
// int float char ... 
// you can define your literal type [ constexpr ctor ]

#include <iostream>

struct ConstStr {
    const char* ptr_;
    std::size_t size_;

    template <size_t N>
    constexpr ConstStr(const char (&a)[N]): ptr_(a), size_(N) {}

    constexpr const char* data() const { return ptr_; }

    constexpr char operator[](unsigned index) { return ptr_[index]; }

    constexpr std::size_t size() const { return size_; }
};

constexpr std::size_t countlower(ConstStr str,unsigned index = 0, size_t count = 0) { 
    if ( index >= str.size()) return count;

    if ( str[index] >= 'a' && str[index] <= 'z' ) return countlower(str, ++index, ++count);
    else return countlower(str, ++index, count);
}


int main() {

    constexpr auto count = countlower("sample text");

    std::cout << count << std::endl;

}
