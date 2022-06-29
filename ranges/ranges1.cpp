#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> x{1, 2, 3, 4, 5};
    // auto it = std::find(x.begin(), x.end(), 4);
    auto it = std::ranges::find(x, 4);
    std::cout << *it;
}
