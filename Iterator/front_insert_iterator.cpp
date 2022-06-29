#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> x{1, 2, 3, 4, 5};
    std::list<int> y;
    std::copy(x.begin(), x.end(), std::front_inserter(y));
    for(int num : y) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}