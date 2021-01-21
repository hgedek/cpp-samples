#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

int main() {

    std::vector<int> v {0, 0, 1,2,3,4,4,4,4,5,6,7,8,9};

    auto lower = std::lower_bound(v.begin(), v.end(), 4);
    auto upper = std::upper_bound(v.begin(), v.end(), 4);

    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
