cmake_minimum_required(VERSION 3.22)
project(SetClass)

set(CMAKE_CXX_STANDARD 17)

# Add warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(SetClass Set.hpp Set.cpp main.cpp)
