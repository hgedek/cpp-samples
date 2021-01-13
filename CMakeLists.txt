cmake_minimum_required(VERSION 3.10)
project(cpp_samples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(address_of address_of.cpp)
add_executable(aliasing_with_template aliasing_with_template.cpp)
