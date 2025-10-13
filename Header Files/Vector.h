#pragma once

#include <cstddef>
#include <mutex>

template <typename T> class Vector
{
private:
    T *m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;

private:
    void ReAlloc(size_t newCapacity)
    {
        // 1. 分配一块额外的内存空间
        // 2. 将已有的内存复制到新的内存空间
        // 3. 删除旧空间

        T *newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

public:
    Vector()
    {
        // 分配两个元素
        ReAlloc(2);
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