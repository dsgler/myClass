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
    long long fac=1;
    for (int i=2;i<=n;i++){
        fac*=i;
    }
    long long pre=sum_fac(n-1);
    return pre+fac;
}