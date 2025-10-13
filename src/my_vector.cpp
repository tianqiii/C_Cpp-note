#include "../Header Files/Array.h"
#include "../Header Files/Vector.h"

#include <cstddef>
#include <iostream>

// 模板原型
template <typename T> void PrintVector(const Vector<T> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << std::endl;
    std::cout << std::string(30, '-') << std::endl;
}

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    // int  *m_MemoryBlock = nullptr;

    Vector3() {}

    Vector3(float scalar) : x(scalar), y(scalar), z(scalar)
    {
        // m_MemoryBlock = new int[5];
    }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3(const Vector3 &other) // = delete;
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied! \n";
    }

    Vector3(Vector3 &&other) : x(other.x), y(other.y), z(other.z)
    {
        // m_MemoryBlock = other.m_MemoryBlock;
        // other.m_MemoryBlock = nullptr;
        std::cout << "Moved! \n";
    }
    // 拷贝赋值
    Vector3 &operator=(const Vector3 &other) //= delete;
    {
        std::cout << "Copy assigned!\n";
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
    // 移动赋值
    Vector3 &operator=(Vector3 &&other) noexcept
    {
        // m_MemoryBlock = other.m_MemoryBlock;
        // other.m_MemoryBlock = nullptr;

        std::cout << "Move assigned!\n";
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    ~Vector3()
    {
        std::cout << "Destroyed! \n";
        // delete[] m_MemoryBlock;
    }
};
// 特化模板 需要传递特定的模板参数而不是T
template <> void PrintVector(const Vector<Vector3> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i].x << "," << vector[i].y << "," << vector[i].z << "\n";
    std::cout << std::string(30, '-') << "\n";
}

int main()
{
    Array<std::string, 2> data;
    data[0] = "ztq";
    data[1] = "C++";

    Vector<std::string> vector;
    vector.PushBack("ztq");
    vector.PushBack("C++");

    vector.EmplaceBack("vector");
    vector.EmplaceBack();
    PrintVector(vector);

    vector.PopBack();
    vector.PopBack();
    PrintVector(vector);

    Vector<Vector3> vec;
    vec.EmplaceBack(Vector3(1.0f));
    /* 输出：
    Moved! -> 右值临时对象移动到内部
    Move assigned! -> Vector内部数组位置赋值
    Destroyed! -> 临时对象销毁
    Des
    */
    vec.EmplaceBack(Vector3(2, 3, 4));
    vec.EmplaceBack(Vector3());
    PrintVector(vec);

    vec.Clear();
    PrintVector(vec);
}