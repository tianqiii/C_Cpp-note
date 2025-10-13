#include <array>
#include <chrono>
#include <iostream>
#include <memory>

class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> m_startTimepoint;

public:
    Timer() : m_startTimepoint(std::chrono::system_clock::now())
    {
        // auto m_startTimepoint = std::chrono::system_clock::now();
    }
    ~Timer()
    {
        Stop();
    }
    void Stop()
    {
        auto m_stopTimepoint = std::chrono::system_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimepoint)
                         .time_since_epoch()
                         .count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_stopTimepoint)
                       .time_since_epoch()
                       .count();

        auto   duration = end - start;
        double ms = duration * 0.001;
        std::cout << duration << "us (" << ms << "ms)\n";
    }
};

int main()
{
    // int value = 0;
    // {
    //     Timer timer;
    //     for (int i = 0; i < 1000000; ++i)
    //     {
    //         value += 2;
    //     }
    // }
    // std::cout << value << std::endl;
    struct Vector2
    {
        float x, y;
    };
    std::cout << "Make share\n";
    {
        std::array<std::shared_ptr<Vector2>, 100000> sharePtr;
        Timer                                        timer;
        for (int i = 0; i < sharePtr.size(); ++i)
        {
            sharePtr[i] = std::make_shared<Vector2>();
        }
    }
    std::cout << "Make new share\n";
    {
        std::array<std::shared_ptr<Vector2>, 100000> sharePtr;
        Timer                                        timer;
        for (int i = 0; i < sharePtr.size(); ++i)
        {
            sharePtr[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }
    std::cout << "Make unique\n";
    {
        std::array<std::unique_ptr<Vector2>, 100000> sharePtr;
        Timer                                        timer;
        for (int i = 0; i < sharePtr.size(); ++i)
        {
            sharePtr[i] = std::make_unique<Vector2>();
        }
    }
}