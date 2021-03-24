#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace fs {
  static uint32_t size(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary | std::ios::ate); 
    return in.tellg();
  }

  static bool exists(const std::string& filename) {
    std::ifstream in(filename);
    return in ? true : false;
  } 
  
  template <typename RT>
  RT readfile(const std::string& filename);


  template <>
  std::string readfile(const std::string& filename) {}

  template <>
  std::vector<std::string> readfile(const std::string& filename) {}

  struct chunk{
      std::string data;

      friend std::ostream& operator<<(std::ostream& out, chunk const& ch) {
        out << ch.data;
        return out;
      }
  };

  template <>
  std::vector<chunk> readfile(const std::string& filename) {}

  template <typename T>
  void print(T&& cont) {
   for (const auto& item : cont) 
      std::cout << item << std::endl; 
  }

  void print(const std::string& text) { std::cout << text << std::endl;}
}

enum {
  HELP = 1,
  WORK = 3
};

int main(int argc, char**argv) {

    if( argc == HELP) {
      std::cout << "usage:\n"
      << "file_reader 'mode' 'filename'\n"
      << "mode:\n"
      << "normal\n"
      << "line\n"
      << "chunk"
      << std::endl;
    } else if ( argc == WORK ) {
      if ( argv [1] == "normal" ) fs::print(fs::readfile<std::string>(argv[2]));
      else if (argv[1] == "line") fs::print(fs::readfile<std::vector<std::string>>(argv[2]));
      else if(argv[1] == "chunk") fs::print(fs::readfile<std::vector<fs::chunk>>(argv[2]));
    }

    return 0;
}

