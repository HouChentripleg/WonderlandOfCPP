#include <iostream>
#include <thread>

int main() {
    std::thread t([](){
        std::cout << "Hello, Concurrency World!" << std::endl;
    });
    t.join();
    return 0;
}