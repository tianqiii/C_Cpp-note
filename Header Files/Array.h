#pragma once

#include <cstddef>

template <typename T, size_t S> class Array
{
private:
    T m_Data[S];

public:
    Array() {}
    constexpr size_t Size() const
    {
        return S;
    }

    T &operator[](size_t index)
    {
        return m_Data[index];
    }

    const T &operator[](size_t index) const
    {
        return m_Data[index];
    }
    T *Data()
    {
        return m_Data;
    }
    const T *Data() const
    {
        return m_Data;
    }
};