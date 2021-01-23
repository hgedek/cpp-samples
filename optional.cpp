#include <optional>
#include <iostream>
#include <vector>
#include <string>

// methods
// has_value | bool operator
// value
// value_or
// operator-> / operator*
// make_optional
// std::nullopt
//

std::optional<std::string> create_user(bool flag) {
    if (flag)
        return std::make_optional("name");
    
    return std::nullopt;
} 

int main() {

    auto user1 = create_user(false);
    if (user1.has_value()) // if (user)
        std::cout << user1.value() << std::endl; // *user

    auto user2 = create_user(true);
    if (user2)
        std::cout << user2.value_or("fake") << std::endl;


    std::optional<int> opt;

    opt = 0;
    std::cout << opt.value() << std::endl;
    
    opt.value() = 1;
    std::cout << *opt << std::endl;

    *opt = 2;
    std::cout << opt.value_or(0) << std::endl;


    opt.emplace(3);
    std::cout << opt.value() << std::endl;

    std::optional<int> opt2 = std::move(opt);
    std::cout << opt2.value() << std::endl;
    std::cout << opt.value_or(-1) << std::endl;

    opt.reset();
    opt2.reset();

    std::cout << opt.value_or(-1) << std::endl;
    std::cout << opt.value_or(-2) << std::endl;

    return 0;

}
