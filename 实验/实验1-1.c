/*实验1-1程序改错与跟踪调试题源程序*/
#include <stdio.h>
#define PI 3.14159
int main(void)
{
    int f;
    short p, k;
    double c, r, s;

    /* 任务1 */
    printf("Input Fahrenheit: ");
    scanf("%d", &f);
    c = 5.0 / 9 * (f - 32);
    printf( " \n %d(F) = %.2f(C)\n\n ", f, c);

    /* 任务2 */
    printf("input the radius r:");
    scanf("%lf", &r);
    s = PI * r * r;
    printf("\nThe acreage is %.2f\n\n", s);

    /* 任务3 */
    k = 0xa1b2, p = 0x8432;
    unsigned short newint = (((unsigned short)k >> 8 ) | ((unsigned short)p & 0xFF00));
    printf("new int = %#x\n\n", newint);
    return 0;
}
