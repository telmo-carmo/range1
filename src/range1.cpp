#include <iostream>
#include <vector>

#include "my_range.hpp"


int main(int argc, char* argv[]) {
    std::cout << "Range example with C++ version: " << __cplusplus << '\n';
    std::vector<int> a{1, 2, 3, 4, 5, 6 };
    std::vector<char> b{'a', 'b', 'c', 'd'};

    auto even = [](int x) { return x % 2 == 0; };
    // Transform: square the numbers
    auto square = [](int x) { return x * x; };

    auto v2 = a | rg::views::filter(even) | rg::views::transform(square);
    int idx = 0;
    for (int x : v2 ) {
        std::cout <<  fmt::format("idx {} = {}\n", idx++,x);
    }

    ts::span<int> sp1(a); 
    auto process_range_part = [](ts::span<const int> s_part) {
        std::cout << "Processing SPAN part: ";
        for (int val : s_part) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    };

    process_range_part(sp1.subspan(0, 4)); 

    return 0;
}