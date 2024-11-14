/*实验3-2程序修改替换第(2)题程序：根据公式计算 s*/
#include <stdio.h>
#define LEN 1024

double mulx(double x, int n);
double fac(int n);
double sum(double x, int n);

double fac_bin[LEN]={1,1};
double mulx_bin[LEN]={1};

double sum(double x, int n)
{
    int i;
    double z = 1.0;
    for (i = 1; i <= n; i++)
    {
        z = z + mulx(x, i) / fac(i);
    }
    return z;
}

double mulx(double x,int n) 
{
    if (mulx_bin[n]!=0) return mulx_bin[n];
    double result = 1.0;
    if (n%2==1){
        result*=x;
    }
    int half_n=n/2;
    double half_result=mulx(x,half_n);
    result*=half_result*half_result;

    mulx_bin[n]=result;
    return result;
}

double fac(int n)
{
    if (fac_bin[n]!=0) return fac_bin[n];
    
    double result=n * fac(n - 1);
    fac_bin[n]=result;
    return result;
}

int main()
{
    double x;
    int n;
    printf("Input x and n: ");
    if (scanf("%lf%d", &x, &n) != 2 || n < 0)
    {
        printf("Invalid input. Please enter a double and a non-negative integer.\n");
        return 1;
    }
    printf("The result is %.16f\n", sum(x, n));
    return 0;
}