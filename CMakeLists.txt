cmake_minimum_required(VERSION 3.22)
project(range1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Using C++ version: ${CMAKE_CXX_STANDARD}")

add_executable(${PROJECT_NAME} src/range1.cpp src/my_range.hpp)

find_package(range-v3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE range-v3::range-v3)

# If using vcpkg, uncomment the following lines to set the toolchain file
#cmake --preset=default
#cmake --build build --config Release
