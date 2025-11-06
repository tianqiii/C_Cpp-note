#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union // 不同方式访问同一块内存（匿名联合体）
    {
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 a, b;
        };
    };
};

void PrintVector2(const Vector2 &v2)
{
    std::cout << v2.x << "," << v2.y << std::endl;
}

int main()
{
    Vector4 v4 = {{1.0f, 2.0f, 3.0f, 4.0f}};

    PrintVector2(v4.a);
    PrintVector2(v4.b);
    std::cout << "=======================" << std::endl;
    v4.z = 500.0f;
    PrintVector2(v4.a);
    PrintVector2(v4.b);
}
