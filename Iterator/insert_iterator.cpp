#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
 
int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{-1, -2, -3};
    std::copy(v.begin(), v.end(), std::inserter<std::list<int>>(l, std::next(l.begin()))); 
    for (int n : l)
        std::cout << n << ' ';
    std::cout << '\n';
    return 0;
}