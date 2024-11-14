/*实验4-2程序修改替换题程序*/
#include <stdio.h>
#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
double sum(double x, double y)
{
    return x + y;
}
int main(void)
{
    int a, b, c;
    double d, e;
    printf("Input three integers:");
    scanf("%d %d %d", &a, &b, &c);
    printf("\nThe maximum of them is %d\n", MAX(a, b, c));

    printf("Input two floating point numbers:");
    scanf("%lf %lf", &d, &e);
    printf("\nThe sum of them is  %f\n", sum(d, e));
    return 0;
}