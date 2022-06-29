#include <iostream>

void may_throw() {
    throw true;
}

auto non_block_throw = []() {
    may_throw();
};

void no_throw() noexcept {
    return;
}

auto block_throw = []() noexcept {
    no_throw();
};

int main() {
    std::cout << std::boolalpha 
        << "may_throw() noexcept? " << noexcept(may_throw()) << std::endl   // false
        << "no_throw() noexcept? " << noexcept(no_throw()) << std::endl     // true
        << "lambda_may_throw() noexcept? " << noexcept(non_block_throw()) << std::endl  // false
        << "lambda_no_throw() noexcept? " << noexcept(block_throw()) << std::endl;      // true

    try {
        may_throw();
    } catch (...) {
        std::cout << "Exception captured from may_throw()!" << std::endl;
    }

    try {
        non_block_throw();
    } catch (...) {
        std::cout << "Exception captured from non_block_throw!" << std::endl;
    }

    try {
        no_throw();
    } catch (...) {
        std::cout << "Exception captured from no_throw()!" << std::endl;
    }

    try {
        block_throw();
    } catch (...) {
        std::cout << "Exception captured from block_throw!" << std::endl;
    }

    return 0;
}