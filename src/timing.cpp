#include <chrono>
#include <iostream>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    Timer()
    {
        start = std::chrono::system_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::system_clock::now();

        std::chrono::duration<float> duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "took " << ms << "ms" << std::endl;
    }
};

void function()
{
    Timer timer; // 作为一种插入函数调试
    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << "\n";
    }
}

int main()
{
    using namespace std::literals::chrono_literals;

    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float> duration = end - start;

    std::cout << duration.count() << std::endl;

    function();

    // std::cin.get();
}