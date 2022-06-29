#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <functional>

int func(int x, int y) {
    return std::pow(x, y);
}

void task_lambda() {
    std::packaged_task<int(int, int)> task([](int a, int b){
        return std::pow(a, b);
    });
    std::future<int> result = task.get_future();
    task(2, 1);
    std::cout << "task_lambda: " << result.get() << std::endl;
}

void task_bind() {
    std::packaged_task<int()> task(std::bind(func, 2, 2));
    std::future<int> result = task.get_future();
    task();
    std::cout << "task_bind: " << result.get() << std::endl;
}

void task_thread() {
    std::packaged_task<int(int, int)> task(func);
    std::future<int> result = task.get_future();
    std::thread td(std::move(task), 2, 3);
    td.join();
    std::cout << "task_thread: " << result.get() << std::endl;
}

int main() {
    task_lambda();
    task_bind();
    task_thread();
    
    return 0;
}