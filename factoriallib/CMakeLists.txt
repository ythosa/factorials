cmake_minimum_required(VERSION 3.16)
project(factoriallib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp fmath.cpp falgo.cpp)
add_executable(my_project_executable ${SOURCES})

#add_executable(factoriallib main.cpp falgo.cpp src/fmath.cpp falgo.h src/fmath.h)