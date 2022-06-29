#include <iostream>
#include <future>
#include <thread>

int main() {
    // 主线程使用std::packaged_task创建异步操作
    std::packaged_task<int()> task([]{ return 1; });  // 模板参数为封装函数的类型
    std::future<int> f1 = task.get_future();
    std::thread(std::move(task)).detach();  // launch线程

    // 主线程使用std::async创建异步操作
    std::future<int> f2 = std::async(std::launch::async, []{ return 2; });
    
    // 主线程使用std::promise创建异步操作
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([&p]{ p.set_value_at_thread_exit(3); }).detach();  // launch线程

    std::cout << "waiting for results...\n";
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\n" << "results are: " << f1.get() << " " << f2.get() << " " << f3.get() << std::endl;
}