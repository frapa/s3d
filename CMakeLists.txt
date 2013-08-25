cmake_minimum_required(VERSION 2.6)
# Project name
project(s3d)

# Find dependencies
#find_package(OpenGL)
#find_package(GLEW)

include_directories(src)

add_definitions(-std=c++11)

add_subdirectory(src build)
add_subdirectory(examples build)
