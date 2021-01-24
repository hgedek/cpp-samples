#include <iostream>
#include <memory>

int main() {


    int x = 0;

    std::unique_ptr<int> ptr;

    assert(!ptr);

    ptr.reset(&x);

    *ptr = 1;

    assert(ptr);

    std::cout << *ptr << std::endl;

    std::unique_ptr<int> ptr2 = std::move(ptr);

    assert(!ptr);

    int* r_ptr = ptr2.get();

    ptr2.release();

    ptr2.reset(new int(3));

    ptr2.release();

    ptr2 = std::make_unique<int>(100);

    assert(*ptr2 == 100);


    std::shared_ptr<int> s;
    
    s = std::make_shared<int>(0);

    assert(s.use_count() == 1);

    decltype(s) s2 = s;

    assert(s.use_count() == 2);

    return 0;
}

