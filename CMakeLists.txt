cmake_minimum_required(VERSION 2.6)
# Project name
project(s3d)

include_directories(include build)

add_definitions(-std=c++11)

add_subdirectory(src bin)
add_subdirectory(examples)
