/*实验3-3跟踪调试题程序：计算fabonacci数列前n项和*/
#include <stdio.h>
long fabonacci(int n);
int main(void)
{
    int i, k;
    long sum = 0, fabonacci(int n);
    printf("Inut n:");
    scanf("%d", &k);
    for (i = 1; i <= k; i++)
    {
        sum += fabonacci(i);
        printf("i=%d\tthe sum is %ld\n", i, sum);
    }
    return 0;
}
long fabonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fabonacci(n - 1) + fabonacci(n - 2);
}