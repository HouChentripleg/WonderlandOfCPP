#include <iostream>
#include <iterator>
#include <sstream>
#include <numeric>

int main() {
    std::istringstream str{"1 2 3 4 5"};
    std::partial_sum(std::istream_iterator<int>(str), 
                     std::istream_iterator<int>{}, 
                     std::ostream_iterator<int>(std::cout, ","));
}