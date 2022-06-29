#include <iostream>
using namespace std;

void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    cout << sizeof...(args) << endl;
    cout << firstArg << endl;
    print(args...);
}

int main() {
    print(729, 729.09, "hello", 'a');
}