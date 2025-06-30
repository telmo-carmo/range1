cmake_minimum_required(VERSION 3.22)
project(range1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(${PROJECT_NAME} src/range1.cpp src/my_range.hpp)

# Detect C++20 or higher
if(CMAKE_CXX_STANDARD GREATER_EQUAL 20)
    message(STATUS "Using C++20 or newer (${CMAKE_CXX_STANDARD})— will use std::format span and ranges")
    set(USE_STD_FORMAT TRUE)
else()
    message(STATUS "Using C++17 — will use fmt::format")
    find_package(range-v3 CONFIG REQUIRED)
    find_package(fmt REQUIRED)
    find_path(TCB_SPAN_INCLUDE_DIRS "tcb/span.hpp")
    set(USE_STD_FORMAT FALSE)
endif()

if(NOT USE_STD_FORMAT)
  target_include_directories(${PROJECT_NAME} PRIVATE ${TCB_SPAN_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} PRIVATE range-v3::range-v3 fmt::fmt)
endif()

# If using vcpkg, uncomment the following lines to set the toolchain file
#cmake --preset=default
#cmake --build build --config Release
