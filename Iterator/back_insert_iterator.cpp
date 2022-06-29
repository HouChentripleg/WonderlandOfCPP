#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> x;
    std::fill_n(std::back_inserter(x), 3, -1);
    for(int num : x) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}