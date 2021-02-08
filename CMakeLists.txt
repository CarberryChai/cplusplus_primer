cmake_minimum_required(VERSION 3.14)
project(cplusplus_primer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
foreach (num RANGE 1 2)
    add_subdirectory("chapter_${num}")
endforeach ()

add_subdirectory(Sales)