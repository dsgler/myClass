#include<stdio.h>

int main(){
    unsigned short num;
    scanf("%d",&num);

    unsigned short low=num & 0b1111;
    unsigned short high=(num>>12) & 0b1111;
    unsigned short middle=num & 0x0FF0;

    num=(low<<12)|(middle)|(high);
    printf("%d",num);
}