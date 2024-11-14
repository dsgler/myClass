#include <stdio.h>
#include <math.h>

int main() {
    int a = 1, b = 1;
    int count = 1; // 从第1项开始计数
    //  1     1     2     3     5     8    13    21
    //  1     1     2     3     5     8    13  
    while (1) {
        if ((int) a/1000000 !=0) { // 使用对数来检查数字的位数
            break;
        }
        count++;
        int next = a + b;
        a = b;
        b = next;
    }

    printf("The first Fibonacci number with more than 6 digits is at position: %d\n", count);
    return 0;
}