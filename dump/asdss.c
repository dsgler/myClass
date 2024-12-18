#include <stdio.h>

int main()
{
    // 这样是不合法的，因为这个 初始化列表 必须分配空间
    // int* p={1,2,3};

    int arr[] = {1, 2, 3};
    int *p = arr;

    printf("%d\n", p[2]);

    int arr2[] = {4, 5, 6};
    const int *p2 = arr;
    arr[0] = 1;
    // 表达式必须是可修改的左值
    // p2[0]=1;

    // 这样是可以的，因为p2并没有被const
    p2 = arr2;

    int *const p3 = arr;
    p3[0] = 2;
    // 表达式必须是可修改的左值,p3本身不可变
    // p3=arr2;

    struct stu
    {
        int num;
        double score;
        char name[12];
    } m, n, *p4;
    m.num=223;
    n=m;
    printf("n.num:%d\n",n.num);
    // 只有在初始化时才能用 初始化列表 ，其它时候只能一个个修改
    // n.name="123";
}