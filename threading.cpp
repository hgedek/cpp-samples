#include <functional>
#include <thread>
#include <vector>
#include <iostream>

decltype(auto) callback(int& value) {
    static int i = 0;
    value += i++;
    printf("%d\n", i);
}

int main() {

    auto counter = 0;

    std::vector<std::thread> th;

    for (auto i = 0; i < 10; i++)
        th.emplace_back(std::thread(callback, std::ref(counter)));

    for (auto i = 0; i < 10; i++)
        th[i].join();

    std::cout << counter << std::endl;

}
