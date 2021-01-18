#include <algorithm>
#include <iostream>
#include <vector>

template <class FwdItr, class T>
constexpr FwdItr lower(FwdItr first, FwdItr end, T const& value) {
    
    FwdItr itr;

    typename std::iterator_traits<FwdItr>::difference_type count, step;

    count = std::distance(first, end);

    while (count > 0) {
        
        itr = first;
        step = count/2;

        std::cout << "step:" << step << std::endl;

        std::advance(itr, step);
        
        if (*itr < value) {
            first = ++itr;
            std::cout << *first << std::endl;
            std::cout << "count:" << count << std::endl;
            count -= step + 1;
            std::cout << "count:" << count << std::endl;
        } else {
            count = step;
        }
    }
    
    return itr;
}



int main() {

    std::vector v {0,1,2,3,4,5,6,7,8};

    std::cout << *lower(v.begin(), v.end(), 4) << std::endl;

    std::cout << *std::lower_bound(v.begin(), v.end(), 4) << std::endl;


    return 0;
}
