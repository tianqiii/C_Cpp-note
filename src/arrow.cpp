#include <cstdint>
#include <iostream>

class Entity
{
public:
    int x;

public:
    void Print() const
    {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity *m_Obj;

public:
    ScopedPtr(Entity *entity) : m_Obj(entity) {}

    ~ScopedPtr()
    {
        delete m_Obj;
    }
    const Entity *operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    const ScopedPtr entity = new Entity();
    entity->Print();


    
    int offset = (uintptr_t)&((Vector3 *)nullptr)->z;

    std::cout << offset << std::endl;

    // Entity *ptr = &e;

    // ptr->Print();
}