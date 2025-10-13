// std::async
#include <iostream>
#include <thread>

void task(int id)
{
    std::cout << "Thread " << id << " is running\n";
}

int main()
{
    std::thread t1(task, 1); // 创建一个线程并运行函数 task(1)
    std::thread t2(task, 2); // 创建另一个线程

    // 等待两个线程结束
    t1.join();
    t2.join();

    std::cout << "Main thread finished\n";
    return 0;
}
