#include <chrono>
#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    std::cout << "id=" << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        std::cout << "working...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // std::cin.get();
    }
}

int main()
{
    std::thread worker(DoWork); // 接受一个函数指针

    std::cin.get();
    s_Finished = true;

    worker.join();

    std::cout << "Done!" << std::endl;
}