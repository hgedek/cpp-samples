#include <iterator>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

// all - none - any...of

std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};

void test_all_none_any_of() {

    //all : all list should pass the test

    auto all = std::all_of(v.begin(), v.end(), [](int p) { return p % 2 == 0; });

    // any : at least 1 should pass the test
    auto any = std::any_of(v.begin(), v.end(), [](int p) { return p % 2 == 0; });

    // none: none of the list should pass the test
    auto none = std::none_of(v.begin(), v.end(), [](int p) { return p% 2 ==0; });

    std::cout << std::boolalpha << "all:" << all << " any:" << any << " none:" << none << std::endl; 
}


void test_for_each() {

    std::for_each(v.begin(), v.end(), [](int p) { std::cout << p << ' '; });
    std::cout << std::endl;
}


void test_count() {
    // count, count_if
    auto c1 = std::count(v.begin(), v.end(), 3);

    auto c2 = std::count_if(v.begin(), v.end(), [](auto i) { return i %2 == 0; });

    std::cout << c1 << ":" << c2 << std::endl;
}

void test_find() {
    // find, find_if, find_if_not
    // string, map, unordered_map...have member finds ( faster and specialized: prefer them)
    // vector...deque... dont have finds
    //
    
    auto itr = std::find(v.begin(), v.end(), 3);
    if (itr != v.end()) std::cout << "found" << std::endl;

    itr = std::find_if(v.begin(), v.end(), [](auto value) { return value == 3; }); // if 3
    if (itr != v.end()) std::cout << "found" << std::endl;

    itr = std::find_if_not(v.begin(), v.end(), [](auto value) { return value == 3; }); // if not 3
    if ( itr != v.end()) std::cout << "found" << std::endl;
}

void test_find_first_of() {
    // find_first_of(beg1,end1,beg2,end2)->itr1
    std::string text = "sample text;sample:...";
    std::string delims =" ;:,.";

    auto itr = std::find_first_of(text.begin(), text.end(), delims.begin(), delims.end());
    if (itr != text.end()) 
        std::cout << "found:" << std::distance(text.begin(), itr) << std::endl;
}

void test_search() {
    // search(beg1,end1, beg2, end2) -> itr1
    std::string text = "sample text fsafdsaf";
    std::string key = "fsa";

    auto result = std::search(text.begin(), text.end(), key.begin(), key.end());
    if (result != text.end()) 
        std::cout << "found" << std::endl;
}

// search for a sequence of sth like 4 4 => 4444
void test_search_n() {
    // search_n(beg1, end1, count, value) -> iter
    // searches count numbered sequence in beg-end with value => value
    
    std::string text = "aaaabbbcc";

    auto itr = std::search_n(text.begin(), text.end(), 3, 'a');
    if (itr != text.end()) std::cout << "found:" << std::distance(text.begin(), itr) << std::endl;

    itr = std::search_n(text.begin(), text.end(), 4, 'b');
    if (itr == text.end())
        std::cout << "not found" << std::endl;


}

void test_mismatch() {
    // mismatch
    std::string s = "test";
    std::string t = "tes";

    auto result = std::mismatch(s.begin(), s.end(), t.begin());

    auto result2 = std::mismatch(s.begin(), s.end(), s.rbegin());

    std::cout << std::distance(s.begin(), result.first) << std::endl;

    std::cout << std::distance(s.begin(), result2.first) << std::endl;
}

void test_copy() {
    // copy, copy_if
    // target can be : itr or back_insert, inserter... or iterator like ostream_iterator

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    std::vector<int> v2(v.size());
    
    // array to array copy so prepare size before
    std::copy(v.begin(), v.end(), v.begin()) ;
    std::cout << v2.size() << std::endl;
    
    std::vector<int> v3;

    std::copy(v.begin(), v.end(), std::back_inserter(v3));
    std::cout << v3.size() << std::endl;

    std::vector<int> v4;

    std::copy(v.begin(), v.end(), std::inserter(v4, v4.end()));
    std::cout << v4.size() << std::endl;
}

void test_transform() {
    // transform(beg1, end1, beg2, pred)
    // transform(beg1, end1, beg2, beg3, pred)

    std::vector<int> v1 = {0,1,2,3,4};

    std::vector<int> v2;

    std::transform(v1.begin(), v1.end(), std::back_inserter(v2), [](int val) { return val * 2; });

    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> v3;

    std::transform(v1.begin(), v1.end(),
                   v2.begin(), std::back_inserter(v3),
                   std::plus<>());

    std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // lower & upper
    //
    std::string s = "fdsfdsafdsafdsaf";
    std::cout << s << " : ";

    std::transform(s.begin(), s.end(), s.begin(), toupper);

    std::cout << s << " : ";

    std::transform(s.begin(), s.end(), s.begin(), tolower);
    std::cout << s << std::endl;
}

void test_unique() {

    std::vector<int> v1 = {0,1,1,1,1,2,2,2,3};

    auto it = std::unique(v1.begin(), v1.end());
    v1.erase(it, v1.end());

    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));

    std::string s = "aaaa";
           
    auto itr = std::unique(s.begin(), s.end());
    if ( itr == s.end()) throw;

    std::cout << std::distance(s.begin(), itr) << std::endl;
                     
    s.erase(itr, s.end());
                        
    std::cout << s << std::endl;
}

void test_rotate() {
    // rotate(beg, next_beg, end)

    std::string s = "abcde";

    // rotate to left
    std::rotate(s.begin(), s.begin() + 2, s.end());

    std::cout << s << std::endl;
    
    // rotate to right
    std::rotate(s.rbegin(), s.rbegin() + 2, s.rend());

    std::cout << s << std::endl;

}

void test_generate(){

    std::vector<int> v(10);

    std::generate(v.begin(), v.end(), [counter = 0] () mutable { return counter++; });

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

void test_reduce() {

    std::cout << "reduce:" <<  std::reduce(v.begin(), v.end(), 0) << std::endl;

    std::cout << "min_reduce:" << std::reduce(v.begin(), v.end(), 100, std::minus<>()) << std::endl;
}

void test_equal() {
    // equal(beg1, end1, beg2)
    // checks if two container equal

    std::string s = "abcba";
    std::string s2 = "fafafa";

    auto res1 = std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
    auto res2 = std::equal(s2.begin(), s2.begin() + s2.size()/2, s2.rbegin());

    std::cout << s << " " << std::boolalpha << res1 << " " << s2 << " " << res2 << std::endl;
}

void test_accumulate() {

    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;

    std::cout << std::accumulate(v.begin(), v.end(), 1, std::multiplies<>()) << std::endl;
}

void test_inner_product() {
    // beg1, end1, beg2, init, plus<>, multiplies
    // init + beg1 * beg2 
    std::vector v1 = {1,2,3};
    std::vector v2 = {4,5,6};

    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << std::endl;

    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,  
            [](auto a, auto b) { return a +b; }, 
            [](auto a, auto b) { return a*b; }) << std::endl;
}

int main() {

    test_all_none_any_of();
    test_for_each();
    test_count();
    test_mismatch();
    test_find();
    test_find_first_of();
    test_search();
    test_search_n();
    test_copy();
    test_transform();
    test_unique();
    test_equal();
    test_rotate();
    test_reduce();
    test_generate();
    test_accumulate();
    test_inner_product();
}


