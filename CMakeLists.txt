cmake_minimum_required(VERSION 3.10)

project(ratio)

add_subdirectory(lib)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(test)
endif ()
