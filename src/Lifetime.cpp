#include <iostream>
#include <memory> // 智能指针

class Entity
{
public:
    Entity()
    {
        std::cout << "Create" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroy" << std::endl;
    }
    void Print() {}
};

class ScopedPtr
{
private:
    Entity *m_Ptr;

public:
    ScopedPtr(Entity *ptr) : m_Ptr(ptr) {}
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

// void *CreateArray() {} // 返回指针的普通函数。

int main()
{
    {
        std::shared_ptr<Entity> e0;
        { // 在这里执行构建函数
            ScopedPtr e = new Entity();
            // new 操作是找到一块足够大的内存，再返回该内存的地址

            std::unique_ptr<Entity> entity(new Entity());
            // 必须显式调用构造函数
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;

            // weak_ptr复制时不会增加shared_ptr的引用次数
            std::weak_ptr<Entity> weak = e0;

            entity->Print();
        } // 在这里执行析构函数
    }
}