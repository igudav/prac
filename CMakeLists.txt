cmake_minimum_required(VERSION 3.13)
project(prac)

find_library(PTHREAD_LIBRARY pthread)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -g)
add_executable(prac "pbs 10/1.cpp")
#add_executable(prac "sem 2019-04-22/ping pong mod.cpp")
#add_executable(prac main.cpp)

target_link_libraries(prac ${PTHREAD_LIBRARY})
