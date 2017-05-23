 # cmake list used to collect sources
cmake_minimum_required(VERSION 3.0.2)

include(FileUtils)
set(ProjectName "Rally")

# Add include directories
include_directories(common)

# Use C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Collect sources
GET_CPP_RECURSIVE( ${CMAKE_CURRENT_SOURCE_DIR} RALLY_CPPS )

# Add dependecies
set(LINKED_LIBRARIES "") # Add required libraries

add_executable(${ProjectName} ${RALLY_CPPS})
target_link_libraries(${ProjectName} ${LINKED_LIBRARIES})
