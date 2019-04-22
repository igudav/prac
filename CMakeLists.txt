cmake_minimum_required(VERSION 3.13)
project(prac)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-std=gnu++17 -pthread -Wall -g)

add_executable(prac "pbs 5/6.cpp")
#add_executable(prac "sem 2019-04-15/thr2.cpp")
#add_executable(prac main.cpp)