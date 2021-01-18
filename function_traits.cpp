#include <iostream>
#include <tuple>

// decltype for all function (member or not ) will return a type as
// RT(...)(Args) so 
// members will be T::* and non-members or statics will be (*) ... 
// (*) => function
// * => others

template <class T> // here we will trigger second specialization with &T::operator() => (S::*)(Args...)
struct function_traits: public function_traits<decltype(&T::operator())>{};

template <class CT, class RT, class...Args>
struct function_traits<RT(CT::*)(Args...) const > {
    enum {
        num_args = sizeof...(Args)
    };

    typedef RT result_type;

    template <size_t N>
    struct arg {
        typedef typename std::tuple_element<N, std::tuple<Args...>>::type type;
    };
};

struct S {
    void operator()(int,float,double) const {}
};

int main() {

    std::cout << function_traits<S>::num_args << std::endl;

    std::cout << typeid(function_traits<S>::arg<2>::type).name() << std::endl;
}

