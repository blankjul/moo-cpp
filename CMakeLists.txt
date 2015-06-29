cmake_minimum_required(VERSION 2.8)
project(MOO CXX)

###############################################################################
# General
###############################################################################
add_definitions(-std=c++11)
add_definitions(-Wextra)

include_directories(BEFORE ".")
include_directories(BEFORE "src/")
include_directories(BEFORE "test/")
include_directories(BEFORE "benchmark/")


###############################################################################
# Google Mock & Test
###############################################################################
add_subdirectory(vendor/gmock-1.7.0)
add_subdirectory(vendor/jsoncpp)
include_directories(vendor/gmock-1.7.0/include)
include_directories(vendor/gmock-1.7.0/gtest/include)
include_directories(vendor/jsoncpp/include)

###############################################################################
# Benchmark
###############################################################################
add_subdirectory(vendor/benchmark)
include_directories(vendor/benchmark/include)


###############################################################################
# moo-cpp library
###############################################################################
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "src/main/nsgaII.cpp")
list(REMOVE_ITEM SOURCES "src/main/moead.cpp")
add_library(moo ${SOURCES})

# Set link libraries
target_link_libraries(moo jsoncpp_lib_static)


###############################################################################
# moo-cpp executable
###############################################################################
add_executable(nsgaII "src/main/nsgaII.cpp")
target_link_libraries(nsgaII moo)

add_executable(moead "src/main/moead.cpp")
target_link_libraries(moead moo)


###############################################################################
# Tests executable
###############################################################################
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
add_executable(tests ${TEST_FILES})
target_link_libraries(tests gmock gtest pthread benchmark moo)



###############################################################################
# Benchmark executable
###############################################################################
file(GLOB_RECURSE BENCHMARK_FILES "benchmark/*.cpp")
add_executable(benchmark_ ${BENCHMARK_FILES})
target_link_libraries(benchmark_ benchmark moo)




