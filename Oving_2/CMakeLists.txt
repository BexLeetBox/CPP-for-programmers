cmake_minimum_required(VERSION 3.24)
project(Oving_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave_1 executable
add_executable(Oving_2_1
        Oppgave_1.cpp)

# Oppgave_4 executable
add_executable(Oving_2_4
        Oppgave_4.cpp)

# oppgave_5 executable
add_executable(Oving_2_5
        oppgave_5.cpp)

# Oppgave_6 executable
add_executable(Oving_2_6
        Oppgave_6.cpp)
