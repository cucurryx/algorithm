cmake_minimum_required(VERSION 3.3)
project(Digraph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Digraph.h
    main.cpp
    tinyDG.txt)

add_executable(Digraph ${SOURCE_FILES})