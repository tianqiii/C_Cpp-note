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

    Vector3() {}

    Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied! \n";
    }

    Vector3(Vector3 &&other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Moved! \n";
    }

    Vector3 &operator=(const Vector3 &value)
    {
        std::cout << "Copy assigned!\n";
        if (this != &value)
        {
            x = value.x;
            y = value.y;
            z = value.z;
        }
        return *this;
    }

    ~Vector3()
    {
        std::cout << "Destroyed! \n";
    }
};
// 特化模板
template <> void PrintVector(const Vector<Vector3> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i].x << "," << vector[i].y << "," << vector[i].z << "\n";
}

int main()
{
    Array<std::string, 2> data;
    data[0] = "ztq";
    data[1] = "C++";

    Vector<std::string> vector;
    vector.PushBack("ztq");
    vector.PushBack("C++");
    // vector.EmplaceBack("vector");
    Vector<Vector3> vec;
    vec.PushBack(Vector3(1.0f));
    vec.PushBack(Vector3(2, 3, 4));
    vec.PushBack(Vector3());

    PrintVector(vector);
}