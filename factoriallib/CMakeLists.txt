cmake_minimum_required(VERSION 3.16)
project(factoriallib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES fmath.cpp falgo.cpp)
set(HEADERS fmath.h falgo.h)

add_library(factoriallib STATIC ${SOURCES} ${HEADERS})
