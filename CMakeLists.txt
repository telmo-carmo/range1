cmake_minimum_required(VERSION 3.22)
project(range1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(range1 range1.cpp my_range.hpp)

find_package(range-v3 CONFIG REQUIRED)
target_link_libraries(range1 PRIVATE range-v3::range-v3)

# If using vcpkg, uncomment the following lines to set the toolchain file
#cmake --preset=default
#cmake --build build --config Release
