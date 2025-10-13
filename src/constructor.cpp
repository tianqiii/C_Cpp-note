#include <iostream>

class Entity
{
public:
    float X, Y; // c++中必须手动初始化

    Entity() // 构造函数
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Constructed Entity" << std::endl;
    }

    Entity(float x, float y) // overload 重载
    {
        X = x;
        Y = y;
    } // 在执行静态函数时不会执行构造函数

    // void init()
    // {
    //     X = 0.0f;
    //     Y = 0.0f;
    // }

    ~Entity() // 析构函数
    {
        std::cout << "Destroyed Entity" << std::endl;
    }

    void Print()
    {
        std::cout << X << "," << Y << std::endl;
    }
};

class Log
{
private:
    Log() {}; // 隐藏构造函数,阻止创建实例

public:
    // Log() = delete; // 或者删除构造函数

    static void Write() {}
};

int main()
{
    // Log::Write();
    // Log l;

    Entity e;
    // e.init();
    e.Print();
}