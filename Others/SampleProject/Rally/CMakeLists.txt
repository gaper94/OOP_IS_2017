# Main cmake list for rally project
cmake_minimum_required(VERSION 3.0.2)
 
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${ROOT_DIR}/cmake/Modules/)

# Set build type
set(CMAKE_BUILD_TYPE "Debug")

# Add subdirectories
add_subdirectory(src)
