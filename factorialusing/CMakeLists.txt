cmake_minimum_required(VERSION 3.16)
project(factorials)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SOURCES main.cpp)
add_executable(factorials ${SOURCES})

include(FindPkgConfig)
find_package(Factoriallib REQUIRED)
include_directories(${FACTORIALLIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FACTORIALLIB_LIBRARY})
