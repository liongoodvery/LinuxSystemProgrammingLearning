cmake_minimum_required(VERSION 3.6)
project(tapue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -lpthread")

add_subdirectory(signal)
add_subdirectory(thread)

include_directories(.)
include_directories(signal)
