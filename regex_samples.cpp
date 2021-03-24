#include <iostream>
#include <regex>
#include <string>
#include <iterator>
#include <algorithm>
/*
 * \t: Tab
 * \d: digit [[:digit:]]
 * \v: vertical Tab
 * .: anything
 * \r: return
 * \D: not digit [^[:digit]]
 * \s: Space [[:space:]]
 * \S: not Space [^[:space]]
 * \w: word [_[:alnum:]]
 * \W: not word [^_[:alnum:]] 
 * \u: unicode
 * \x: hexacode
 * [xyz]: x or y or z
 * [^xyz]: not ( x or y or z)
 * classes:
 * [:alnum:] : alpha numerical
 * [:alpha:] : alpha
 * [:blank;] : blank
 * [:cntrl:] : control
 * [:digit:] : digit
 * [:lower:] : lower
 * [:upper:] : upper
 * [:xdigit:]: hexadecimal
 * [:punct:] : punctions
 * [:d:] : deciaml
 * [:w:] : word
 * [:s:] : whitespace
 *
 * *: 0 or more
 * +: 1 or more
 * ?: 0 or 1
 * {int}: int
 * {int,}: int or more
 * {min,max}: min = max
 * 
 * ((subpattern)): groups
 * (?:subpattern): passive group => doesnt create back reference
 * ^: beginning of line
 * $: end of the line
 * \b: word boundary
 * \B: not word boundary
 * | : seperater...two alternative patterns
*/

// regex_token_iterator
void token_iterator_test(){

  std::cout << "token_iterator:" << std::endl;

  const std::string text = "sample text   to split words";

  std::regex re(R"(\s+)");

  // get the left and right of searched items 
  std::sregex_token_iterator beg(text.begin(), text.end(), re, -1);
  std::sregex_token_iterator end;

  while( beg != end) {
    std::cout << *beg++ << '\n';
  }

  std::cout << std::endl;


  std::sregex_token_iterator beg2(text.begin(), text.end(), re);
  std::sregex_token_iterator end2;
  
  std::cout << "token_iterator2: " << std::endl;
  
  while( beg2 != end2) {
    std::cout << *beg2++ << '\n';
  }

  std::cout << std::endl;

  std::sregex_token_iterator beg3(text.begin(), text.end(), re, 1);
  std::sregex_token_iterator end3;

  std::cout << "token_iterator3" << std::endl;

  while ( beg3 != end3 ){
    std::cout << *beg3++ << '\n'; 
  }

  std::cout << std::endl;
}

void regex_match_test() {
  std::regex re("(soft)(.*)");

  std::string word = "software";

  auto result = std::regex_match(word, re);
  std::cout << std::boolalpha << result << std::endl;

  std::smatch sm;
  std::regex_match(word, sm, re);

  std::cout << sm.size() << std::endl;
  std::cout << "word:" << sm[0] << '\n' 
      << "first:" << sm[1] << '\n' 
      << "second:" << sm[2] << std::endl;
}

void regex_search_test() {
  std::string text = "hello world";
  std::regex re("(wor)(.*)");

  std::smatch sm;
  std::regex_search(text, sm, re);

  std::cout << sm[0] << ":" << sm[1] << ";" << sm[2] << std::endl;


  std::string s = "this subject has a submarine as a subsequence";
  std::smatch m;
  std::regex re2("\\b(sub)([^ ]*)");
  
  while (std::regex_search(s, m, re2)) {
     for (auto x : m) {
       std::cout << x << std::endl; 
     }
    
     s = m.suffix().str();
     std::cout << s << std::endl;
  }
}

void split() {
  const std::string text = "a b c  d   e f   g h i j k   l m o";
  std::regex re("\\s+");
  
  std::sregex_token_iterator beg(text.begin(), text.end(), re, -1);
  std::sregex_token_iterator end;

  while (beg != end) {
    std::cout << *beg++ << " ";
  }
}

int main() {
  token_iterator_test();
  regex_match_test();
  regex_search_test();
  split();
}
