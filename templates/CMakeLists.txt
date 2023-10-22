cmake_minimum_required(VERSION 3.22)
project(templates)

set(CMAKE_CXX_STANDARD 17)

# Add -Wall flag for g++
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall)
endif()

add_executable(templatesPair oppgave-2/Pair.cpp)

add_executable(templates oppgave-1/template.cpp)
