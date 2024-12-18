#include <stdio.h>

// *是指返回值是指针
// c中是不能直接返回数组的，只能返回数组的指针
int (*pf())[5]
{
    static int arr[5] = {1, 2, 3, 4, 5};
    return &arr;
}

int main()
{
    // 这里是函数指针数组
    // (*p[1]) 是对p的具体描述，即指针数组
    // 外面是对函数的描述，copy即可
    int(*(*p[1])())[5] = {pf};
    int(*arr)[5] = p[0]();
    printf("%d\n", (*arr)[2]);
}
