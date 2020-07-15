cmake_minimum_required(VERSION 3.16)
project(factoriallib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp include/fmath.cpp include/falgo.cpp)
add_library(factorial ${SOURCES})
