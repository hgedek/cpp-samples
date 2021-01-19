#include <iostream>
#include <sstream>
#include <string>


int main() {
    
    std::string text = "    sample text    ";
    std::istringstream is{text};

    std::string str;

    std::istream_iterator<std::string> it { is >> std::skipws }, end;

    while ( it != end )
        std::cout << *it++ << std::endl;
}
