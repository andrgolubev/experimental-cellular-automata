cmake_minimum_required(VERSION 2.8)
project(cellular_automata_experimental)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
endif()

add_subdirectory(cellular_automata_impl)
add_subdirectory(random)
