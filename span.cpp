#include <span>
#include <vector>
#include <string>
#include <iostream>
#include <ranges>
#include <cstdio>

template <typename T>
void print(const std::span<T> s) {
  for (auto& item : s)
    std::cout << item << " ";

  std::cout << '\n';
}

void sub_first() {
  const std::string text = "hakan gedek";
  const std::span s {text};

  const std::span<const char> first_3 = s.first<3>();
  std::cout << first_3.data() << std::endl;
  print(first_3);

  std::cout << s.first(3).data() << std::endl;
}

void sub_last() {
  const std::string text = "hakan gedek";
  const std::span s{text};

  std::cout << s.last<3>().data() << std::endl;
  std::cout << s.last(3).data() << std::endl;

  const std::span<const char, 3> last_3 = s.last<3>();
  std::cout << last_3.data() << std::endl;
}

void reverse() {
  std::string text = "hakan gedek";
  std::span s {text};

  for (std::size_t i = 0, j = s.size()-1; i < j; i++,j--)
    std::swap(s[i], s[j]);

  print(s);
}

void subs() {
  const std::string text {"hakan gedek"};
  const std::span s {text};

  for (size_t i = 0; i < s.size(); i++) {
    const auto ss = s.subspan(i, 3);
    std::for_each(ss.begin(), ss.end(), std::putchar);
    std::putchar('\n');
  }

  std::putchar('\n');
}

int main() {

  std::vector v {0,1,2,3,4,5,6};
  std::string s {"hakan"};
  int A[5] = {0,1,2,3,4};

  print(std::span{v});
  print(std::span{s});
  print(std::span{std::begin(A), std::end(A)});
  // print(std::span{A});

  sub_last();
  sub_first();

  reverse();
  subs();

  const std::string data = "Hakan Gedek";
  const std::span sp {data};
  std::cout << data << std::endl;

  return 0;
}
