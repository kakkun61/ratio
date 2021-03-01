add_library(ratio STATIC ratio.cpp)

target_compile_features(ratio PRIVATE cxx_std_17)

if (MSVC)
    target_compile_options(ratio PRIVATE /Wall)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(ratio PRIVATE -Wall)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(ratio PRIVATE -Wall -Wno-c++98-compat Wno-c++11-extensions)
endif()
