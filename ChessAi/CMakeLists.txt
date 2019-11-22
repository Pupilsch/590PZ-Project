cmake_minimum_required(VERSION 3.9)
project(ChessAi)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessAi main.cpp board.hpp piece.hpp)