cmake_minimum_required(VERSION 3.10)
project(encrypto)

set(CMAKE_CXX_STANDARD 14)

add_executable(encrypto main.cpp Phrase.h Phrase.cpp game.h game.cpp)