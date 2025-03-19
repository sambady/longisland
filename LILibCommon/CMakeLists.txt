cmake_minimum_required(VERSION 3.24.0)

project(LILibCommon)

add_library(LILibCommon
./source/algorithm/algorithm_position.cpp
./source/algorithm/algorithm_position.h
./source/msgpack/msgpack.hpp
./source/navmesh/cone_of_vision.cpp
./source/navmesh/cone_of_vision.h
./source/navmesh/navmesh_type_converter.cpp
./source/navmesh/navmesh_type_converter.h
./source/navmesh/path_finder.cpp
./source/navmesh/path_finder.h
./source/navmesh/point.cpp
./source/navmesh/point.h
./source/navmesh/pointf.h
./source/navmesh/polygon.cpp
./source/navmesh/polygon.h
./source/navmesh/segment.cpp
./source/navmesh/segment.h
./source/types/actor_id.h
./source/types/position.cpp
./source/types/position.h
)

target_compile_features(LILibCommon PRIVATE cxx_std_20)