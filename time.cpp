#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>


int main() {


    std::tm t{};

    std::istringstream is{"2012-02-13 02:00:14"};

    is >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");

    if(is.fail())
        std::cout << "Parse failed";
    else
        std::cout << std::put_time(&t, "%c") << std::endl;

}
