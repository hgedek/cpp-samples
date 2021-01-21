#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

void no_delim(std::string const& str) {

    std::istringstream iss{str};
    std::string word;

    while(iss) {
        iss >> word;

        if (!word.empty())
            std::cout << word << std::endl;

        word = "";
    }
}

void with_delim(std::string const& str, char delim) {

    std::istringstream iss{str};
    std::string word;

    while(std::getline(iss, word, delim)){
        std::cout << word << std::endl; 
    }
}

void no_delim_iterator(std::string const& str) {

    std::istringstream iss{str};
    std::istream_iterator<std::string> itr{iss}, end;

    while(itr != end) {
        std::cout << *itr++ << std::endl; 
    }
}

void with_find(std::string_view str) {
    std::string_view delims = " :;";
    auto beg = 0, end = 0;

    while((beg = str.find_first_not_of(delims, end)) != std::string::npos) {
        end = str.find_first_of(delims, beg);
        std::cout << str.substr(beg, end-beg) << std::endl;
        
    }
}

int main() {

    std::string text = " fdfds  fdfd f ds fds af ds f dsa fds ";

    no_delim(text);

    std::cout << std::endl;

    no_delim_iterator(text);

    std::cout << std::endl;

    with_delim(text,' ');

    std::cout << std::endl;

    text = "fdsff:fdsafsd;fdsafdsaf;fdafdsa";

    with_delim(text,';');

    std::cout << std::endl;

    with_find(text);

    return 0;

}
