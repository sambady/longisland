cmake_minimum_required(VERSION 3.24.0)

project(LongIsland)

message("Hello world")

add_subdirectory(LILibCommon)
add_subdirectory(LIClient)

add_dependencies(LIClient LILibCommon)
