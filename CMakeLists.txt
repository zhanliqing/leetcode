cmake_minimum_required(VERSION 3.2)
project(leetcode)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-std=c++11")             # c++11
set(CMAKE_CXX_FLAGS "-ggdb")
set(CMAKE_CXX_FLAGS "-Wall")

#set(CMAKE_CXX_FLAGS_DEBUG "-O1")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ")
set(SOURCE_FILES
        src/c_plus/215-kth-largest-element-in-an-array/solution.cpp
        src/c_plus/util.h)

add_executable(solution ${SOURCE_FILES})