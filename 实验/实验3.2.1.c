/*实验3-1改错题程序：计算s=1!+2!+3!+…+n!*/
#include <stdio.h>
long long sum_fac(int n);
int main(void)
{
    int k;
    for (k = 1; k <= 20; k++)
        printf("k=%d\tthe sum is %lld\n", k, sum_fac(k));
    return 0;
}
long long sum_fac(int n)
{
    if (n==1){
        return 1;
    }
    long long s = 0;
    int i,j;
    long long fac;
    for (j=1;j<=n;j++){
        for (i = 1,fac=1; i <= j; i++)
            fac *= i;
        s += fac;
    }
    return s;
}
