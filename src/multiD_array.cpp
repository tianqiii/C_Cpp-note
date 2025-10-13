#include <iostream>

int main()
{
    int  *array = new int[50];
    int **a2d = new int *[50];

    for (int i = 0; i < 50; ++i)
    {
        a2d[i] = new int[50];
    }
    // 删除 避免内存泄漏
    for (int i = 0; i < 50; ++i)
    {
        delete[] a2d[i];
    }
    delete[] a2d;

    int ***a3d = new int **[50];

    for (int i = 0; i < 50; ++i)
    {
        a3d[i] = new int *[50];
        for (int j = 0; j < 50; ++j)
        {
            a3d[i][j] = new int[50];
        }
    }
    // 删除
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }
    delete[] a2d;

    // a3d[0][0][0] = 0;

    int *arr2 = new int[5 * 5]; // 扁平化
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            arr2[x + y * 5] = 2;
        }
    }
}