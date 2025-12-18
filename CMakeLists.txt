cmake_minimum_required(VERSION 4.1)
project(VertexCoverMapRepo)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(VertexCoverMapRepo
        main.cpp
        graph.h)
