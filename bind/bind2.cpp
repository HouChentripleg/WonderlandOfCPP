#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

bool MyPredict(int val1, int val2) {
    return val1 > val2;
}

int main() {
    std::vector<int> x{1, 2, 3, 4, 5, 6};
    std::vector<int> y;
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind(MyPredict, std::placeholders::_1, 3));
    for(int num : y) {
        std::cout << num << ' ';    // 输出4 5 6
    }
    std::cout << "\n";
    return 0;

}