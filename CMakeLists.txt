cmake_minimum_required(VERSION 3.14)
project(cplusplus_primer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
foreach (num RANGE 1 8)
    add_subdirectory("chapter_${num}")
endforeach ()