project(factoriallib_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(factoriallib_tests_run falgo_test.cpp fmath_test.cpp)

target_link_libraries(factoriallib_tests_run factoriallib_lib)

target_link_libraries(factoriallib_tests_run gtest gtest_main)
