#include <iostream>
#include <deque>
#include <memory>

template <typename T, template <typename T> class Container>
class Stack {
    Container<T> Ctn;
};

int main() {
    Stack<int, std::deque> st2;
}