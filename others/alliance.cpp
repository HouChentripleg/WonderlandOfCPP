#include <iostream>
#include <cstddef>

struct Storage {
    char a;         // 1
    int b;          // 4
    double c;       // 8
    long long d;    // 8
};                  // 8

struct alignas(std::max_align_t) AlignasStorage {
    char a;
    int b;
    double c;
    long long d;
};

int main() {
    std::cout << alignof(Storage) << std::endl; // 8
    std::cout << alignof(AlignasStorage) << std::endl; // 16

    return 0;
}

// std::max_align_t要求每个scalar标量类型的对齐方式严格一致，即long double
