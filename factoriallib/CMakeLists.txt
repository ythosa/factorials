project(factoriallib)

set(HEADER_FILES
        falgo.h
        fmath.h
        )

set(SOURCE_FILES
        falgo.cpp
        fmath.cpp
        )

add_library(factoriallib_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
