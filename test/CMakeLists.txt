add_executable(ratio_test test.cpp)

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

target_link_libraries(ratio_test PRIVATE ratio GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

gtest_discover_tests(ratio_test)

enable_testing()
