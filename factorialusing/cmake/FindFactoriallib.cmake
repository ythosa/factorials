set(FIND_FACTORIALLIB_PATHS ~/Projects/factorials/factoriallib)

find_path(FACTORIALLIB_INCLUDE_DIR falgo.h fmath.h
        PATH_SUFFIXES include
        PATHS ${FIND_FACTORIALLIB_PATHS})

find_library(FACTORIALLIB_LIBRARY
        NAMES factorial
        PATH_SUFFIXES lib
        PATHS ${FIND_FACTORIALLIB_PATHS})
