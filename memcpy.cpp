#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <vector>
#include <chrono>
#include <cstring>

#define NOW std::chrono::high_resolution_clock::now();


constexpr auto SIZE = 1'000'000;

int main() {
    
    std::vector<int> a(SIZE,1), b(SIZE,0), c(SIZE,0);

    auto now = NOW;
    std::copy(a.begin(), a.end(), b.begin());
    auto diff = NOW;

    std::cout << (diff-now).count() << std::endl;


    now = NOW;
    std::memcpy(&c[0], &a[0], a.size() * sizeof(int));
    diff = NOW;

    std::cout << (diff-now).count() << std::endl;

    return 0;
}
