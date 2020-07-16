project(factoriallib_benchmarks)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(factoriallib_benchmarks_run main.cpp)

target_link_libraries(factoriallib_benchmarks_run factoriallib_lib)

target_link_libraries(factoriallib_benchmarks_run benchmark::benchmark)
