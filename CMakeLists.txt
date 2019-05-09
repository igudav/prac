cmake_minimum_required(VERSION 3.13)
project(prac)

find_library(PTHREAD_LIBRARY pthread)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -g)
#add_executable(pbs "pbs 12/6.cpp")
add_executable(sem "sem 2019-05-06/smth.cpp")
add_executable(main main.cpp)

target_link_libraries(main ${PTHREAD_LIBRARY})
