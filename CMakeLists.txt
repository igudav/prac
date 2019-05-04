cmake_minimum_required(VERSION 3.13)
project(prac)

find_library(PTHREAD_LIBRARY pthread)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -g)
add_executable(pbs "pbs 10/5.cpp")
add_executable(sem "sem 2019-04-29/sem.cpp")
add_executable(main main.cpp)

target_link_libraries(sem ${PTHREAD_LIBRARY})
