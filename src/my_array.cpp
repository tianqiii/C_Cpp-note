#include <alloca.h>
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>

template <typename T, size_t S> class Array
{
private:
    T m_Data[S];

public:
    // Array(int size)
    // {
    //     m_Data = (int *)alloca(size * sizeof(int));
    // }
    constexpr size_t size() const // 这里必须是constexpr 编译时就得确定
    {
        return S;
    }

    const T &operator[](size_t i) const // 常量版本
    {
        if (i >= S)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return m_Data[i];
    }

    T &operator[](size_t i)
    {
        if (i >= S)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return m_Data[i];
    }
};

int main()
{
    // std::array<int, 10> collection;

    // // int size = collection.size();
    // for (int i = 0; i < collection.size(); i++)
    // {
    //     std::cout << collection[i] << "\n";
    // }

    const int        size = 5;
    Array<int, size> data;

    memset(&data[0], 0, data.size() * sizeof(int));

    static_assert(data.size() < 10, "size too large!");
    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "\n";
    }
}