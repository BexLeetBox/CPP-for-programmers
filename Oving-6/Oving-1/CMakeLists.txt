cmake_minimum_required(VERSION 3.22)
project(Oving_5)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(Oving_5
        Main.cpp ChessBoard.h ChessBoardPrint.h)
