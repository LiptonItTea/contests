cmake_minimum_required(VERSION 4.2)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp main.cpp
        E.cpp
        A.cpp
        H.cpp
        string_functions/G.cpp
        D.cpp)
