#include <vector>
#include <iostream>
#include <string>

union S {
    std::string s;
    std::vector<int> v;
    ~S(){}
};

int main() {

    S s {"sampledfsd"};

    std::cout << s.s << std::endl;

    new(&s.s) std::vector<int>;
    
    s.s.push_back(0);

    std::cout << s.v.size() << std::endl;


    return 0;
}
