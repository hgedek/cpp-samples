cmake_minimum_required(VERSION 3.10)
project(cpp_samples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(address_of address_of.cpp)
add_executable(aliasing_with_template aliasing_with_template.cpp)
add_executable(array_type array_type.cpp)
add_executable(variadic_template_indexing variadic_template_indexing.cpp)
add_executable(checked_deletor checked_deletor.cpp)
add_executable(compile_time_next_prev compile_time_next_prev.cpp)
add_executable(constexpr constexpr.cpp)
add_executable(construct construct.cpp)

