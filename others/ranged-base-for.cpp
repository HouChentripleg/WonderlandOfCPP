#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec({1, 2, 3, 4, 5});
    for(auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    for(auto& elem : vec) {
        elem *= 2;
    }
    for(auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}