cmake_minimum_required(VERSION 3.24)
project(Oving_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

include_directories(.)


add_executable(Oving_3_2 Oppgave_2.cpp Circle.cpp Circle.h Commodity.cpp Commodity.hpp)
add_executable(Oving_3_3 Oppgave_3.cpp Circle.cpp Circle.h Commodity.cpp Commodity.hpp)
add_executable(Oving_3_4 Oppgave_4.cpp Circle.cpp Circle.h Commodity.cpp Commodity.hpp)
