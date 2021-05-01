#if defined __has_include
#if __has_include(<concepts>)
#include <concepts>
#include <iostream>

template <typename T, typename ...U>
concept IsAnyOf = (std::same_as<T,U> || ...);

template <typename T>
concept IsPrintable = std::is_integral_v<T> || std::floating_point<T> ||
                      IsAnyOf<std::remove_cvref_t<std::remove_pointer_t<std::decay_t<T>>>, char, wchar_t>;

void println(IsPrintable auto const ... args) {
  (std::cout << ... << args) << "\n";
}

template <typename T>
concept Hashable = requires(T a) {
  { std::hash<T>{}(a)} -> std::convertible_to<std::size_t>;
};

struct A {};
struct B {};

namespace std {
  template <>
  struct hash<A> {
    std::size_t operator()(const A& a) const noexcept {
      return sizeof(a) * 1.3;
    }
  };
}

template <Hashable T>
void foo(T const& ) {}


template <class T, class U>
concept Derived = std::is_base_of<U,T>::value;


int main() {
  println("Example:", "1" , "2", "a", "[", "]" );

  A a;
  foo(a);  

  // B b;
  /// foo(b);
}
#endif
#endif

