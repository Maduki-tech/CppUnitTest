cmake_minimum_required(VERSION 3.1)

project(main)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Locate the source files
file(GLOB SOURCES ./includes/*.h *.cpp ./src/*.cpp)

# Create a library for the main code
add_library(main_lib ${SOURCES})

# Add the main executable
add_executable(main_executable main.cpp)
target_link_libraries(main_executable main_lib)

# Download and install Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
file(GLOB TEST_SOURCES ./tests/*.cpp)
add_executable(test_runner ${TEST_SOURCES})

# Link the Google Test libraries
target_link_libraries(test_runner gtest_main)

# Link the main project library with the test executable
target_link_libraries(test_runner main_lib)

# Enable testing
enable_testing()

# Add a test to be run
add_test(NAME example_test COMMAND test_runner)
