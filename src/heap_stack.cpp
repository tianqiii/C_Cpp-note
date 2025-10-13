#include <stdio.h>
#include <stdlib.h>

// 全局变量 -> 数据段
int global_var;

int main()
{
    // 局部变量 -> 栈
    int stack_var = 10;

    // 动态分配 -> 堆
    int *heap_var = (int *)malloc(sizeof(int));

    printf("地址分布：\n");
    printf("代码段 (函数 main): %p\n", &main);
    printf("数据段 (全局变量):  %p\n", &global_var);
    printf("堆    (动态分配):  %p\n", heap_var);
    printf("栈    (局部变量):  %p\n", &stack_var);

    // 注意：堆地址和栈地址的大小比较
    if (heap_var > (void *)&stack_var)
    {
        printf("注意：在这个系统/配置下，堆地址可能高于栈地址。\n");
        printf("但这不改变栈向低地址生长，堆向高地址生长的本质。\n");
    }
    else
    {
        printf("典型的布局：堆在低地址，栈在高地址。\n");
    }

    free(heap_var);
    return 0;
}