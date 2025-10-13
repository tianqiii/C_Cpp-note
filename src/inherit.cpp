#include <iostream>
// #include <string>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

    virtual std::string GetName() // = 0
    // 虚函数（如果 = 0则为纯虚函数，强制子类实现这个方法） 如果被重写能被找到
    {
        return "Entity";
    }
};

class Player : public Entity // 继承
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name) {};
    std::string GetName() override
    // override 标志这个函数被重写了 写了可以增强代码可读性
    {
        return m_Name;
    }
};

int main()
{
    Entity *e = new Entity();
    std::cout << e->GetName() << std::endl; // "->" 符号代表用指针来访问对象的成员变量或成员函数。

    Player *p = new Player("ztq");
    std::cout << p->GetName() << std::endl;

    Entity *entity = p;
    std::cout << entity->GetName() << std::endl;
}