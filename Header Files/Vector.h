#pragma once

#include <cstddef>
#include <mutex>
#include <new>
#include <utility>

template <typename T> class Vector
{
private:
    T *m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;

private:
    void ReAlloc(size_t newCapacity) // 应该只分配空间而不构造
    {
        // 1. 分配一块额外的内存空间
        // 2. 将已有的内存复制到新的内存空间
        // 3. 删除旧空间

        // 注意，这里使用了new 分配了一个内存空间并且使用构造函数
        // 后面的 delete 可能会导致双重析构错误,可以将分配空间和构造分开
        T *newBlock = new T[newCapacity];
        // T *newBlock = (T *)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);

        // for (size_t i = 0; i < m_Size; i++)
        //     m_Data[i].~T();

        delete[] m_Data;
        // ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

public:
    Vector()
    {
        // 分配两个元素
        ReAlloc(2);
    }

    ~Vector()
    {
        Clear();
        delete[] m_Data;
    }

    void PushBack(const T &value)
    {
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }

        m_Data[m_Size] = value;
        m_Size++;
    }
    // 可变参数模板
    template <typename... Args> T &EmplaceBack(Args &&...args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        // 放在括号后表示展开参数包
        // 完美转发：将参数转发回原来的类别，确保调用左值和右值构造函数

        // m_Data[m_Size] = T(std::forward<Args>(args)...);
        // return m_Data[m_Size++];

        // 原地构造 new(address) T(...) 在address上直接使用T的构造函数构造
        // 高效，避免拷贝，析构时必须手动调用T::~T(),否则会导致内存泄露
        new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    const T &operator[](size_t index) const
    {
        if (index >= m_Size)
        {
        }
        return m_Data[index];
    }

    T &operator[](size_t index)
    {
        return m_Data[index];
    }

    size_t Size() const
    {
        return m_Size;
    }
};