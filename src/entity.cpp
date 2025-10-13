#include <iostream>

struct Entity
{
    static int x, y; // 必须在类外定义静态变量

    static void Print() // static 关键字相当于从(Entity e)去除掉this指针参数
    {
        std::cout << x << "," << y << std::endl;
    }
};

class Singleton // 单实例模式
{
private:
    static Singleton *s_Instance; // 静态指针，指向唯一的示例
    Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    // static Singleton &Get() // 静态方法，获取唯一示例
    // {
    //     return *s_Instance;
    // }

    static Singleton &Get()
    {
        // static Singleton instance;
        return *s_Instance;
    }

    void Hello() {};
};

// Singleton *Singleton::s_Instance = nullptr; // 初始化静态指针为空
Singleton Singleton::*s_Instance = nullptr;

void Function()
{
    static int i = 0; // i 不能在全局访问，只能在局部访问
    i++;
    std::cout << i << std::endl;
}

int Entity::x; // 定义
int Entity::y;

int main()
{

    Singleton::Get().Hello();
    Singleton &s = Singleton::Get(); // 保证不创建副本

    Entity e;
    e.x = 2;
    e.y = 3;

    // Entity e1 = {5, 8}; // 只适用于普通成员变量
    Entity e1;
    Entity::x = 5;
    Entity::y = 8;
    // Entity::Print(); // 静态方法的调用
    // e1.Print();
    Function();
    Function();
    Function();
    Function();
}