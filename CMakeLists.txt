cmake_minimum_required(VERSION 2.8)
project(MOO)

# General
###############################################################################
# Activate C++11 support (if you encounter gmock errors, use 1.6.0 version)
add_definitions(-std=c++11)

# Extra warnings
add_definitions(-Wextra)

# Google Mock & Test
###############################################################################
add_subdirectory(vendor/gmock-1.7.0)
include_directories(vendor/gmock-1.7.0/include)
include_directories(vendor/gmock-1.7.0/gtest/include)

# Main program library
###############################################################################
file(GLOB SOURCES "src/*.cpp")
add_library(moo ${SOURCES})

# Set link libraries
# target_link_libraries($EXECUTABLE_NAME ...)



# Tests executable
###############################################################################
set(TEST_EXECUTABLE_NAME "tests")

# Test files
file(GLOB TEST_FILES "test/*.cpp")

# Don't include Main.cpp from src
file(GLOB MAIN_SRC "src/Main.cpp")
list(REMOVE_ITEM SOURCES ${MAIN_SRC})

add_executable("${TEST_EXECUTABLE_NAME}" ${TEST_FILES} ${SOURCES})

# Set link libraries (order matters)
target_link_libraries("${TEST_EXECUTABLE_NAME}" gmock gtest pthread moo)

# Include root directory
include_directories(BEFORE ".")
include_directories(BEFORE "src/")
include_directories(BEFORE "test/")
