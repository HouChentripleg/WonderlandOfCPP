#include <iostream>
#include <thread>

int main() {
    int a = 0;
    int flag = 0;

    std::thread t1([&](){
        while(flag != 1);
        int b = a;
        std::cout << "b = " << b << std::endl;
    });

    std::thread t2([&](){
        a = 5;
        flag = 1;
    });

    std::cout << "a = " << a << std::endl;

    t1.join();
    t2.join();
    return 0;
}