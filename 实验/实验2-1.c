/* 实验2-1改错题程序：合数判断器*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isHeShu(int x)
{
    int i, k;
    bool flag = false;
    if (x <= 2)
    {
        return false;
    }
    for (i = 2, k = sqrt(x); i <= k && flag != true; i++)
    {
        if (x % i == 0)
        {
            flag = true;
            // break;
        }
    }
    return flag;
}

bool isPureHeShu(int x)
{
    bool flag = true;
    for (; flag == true && x > 0; x /= 10)
    {
        flag = isHeShu(x);
    }
    return flag;
}

int main()
{
    // int x;
    // printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
    // while (scanf("%d", &x) != EOF)
    // {
    //     bool flag=isPureHeShu(x);

    //     if (flag == true)
    //         printf("%d是纯粹合数", x);
    //     else
    //         printf("%d不是纯粹合数", x);
    // }

    for (int x = 100; x < 1000; x++)
    {
        if (isPureHeShu(x))
        {
            printf("%d ", x);
        }
    }
    return 0;
}
