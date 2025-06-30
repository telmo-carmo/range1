#pragma once

#include <vector>

#if __cplusplus >= 202002L
    // C++20: Implement a simple zip view (like C++23)
    #include <ranges>
    #include <tuple>
    #include <iterator>
    #include <utility>

    namespace rg = std::ranges;
    namespace vw = std::ranges::views;

    #include <span> 
    #include <array>
    namespace ts = std; 

#else
    // C++17: Use range-v3
    #include <range/v3/all.hpp>
    #include <range/v3/view/zip.hpp>
    #include <tuple>

    namespace rg = ranges::v3;
    namespace vw = ranges::v3::views;

    #include <tcb/span.hpp> // tcb::span for C++17
    namespace ts = tcb; // Use tcb::span as a replacement for std::
#endif