#include <iostream>
#include <ostream>
#include <vector>

// >>>>>>>> 动态数组 <<<<<<<<

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

// 返回类型为引用; 参数引用，避免ostream拷贝，可以修改; 参数常量引用，避免Vertex拷贝和修改

std::ostream &operator<<(std::ostream &os, const Vertex &v)
{
    os << v.x << "," << v.y << "," << v.z;
    return os;
}

int main()
{
    /*

    第1次拷贝：临时对象 → vector内部存储
    第2次拷贝：重新分配时的拷贝

    优化策略1: 在实际内存中创建顶点，不在主函数中复制
    优化策略2: 如果一开始就知道要分配多少个，一开始就创建足够大小的内存

    */

    std::vector<Vertex> vertices;

    vertices.reserve(3); // 并不构建，只分配足够空间

    // emplace_back 就是直接创建顶点，不是先Vertex构造再复制
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);

    // 这里就是先构建再复制，会额外复制一份，造成额外开销
    vertices.push_back(Vertex(7, 8, 9));

    // for (int i = 0; i < vertices.size(); i++)
    // {
    //     std::cout << vertices[i] << std::endl;
    // }

    for (const Vertex &v : vertices)
    {
        std::cout << v << std::endl;
    }
}