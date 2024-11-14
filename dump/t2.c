#include<stdio.h>

int main(){
    short i=0xFFFF;
    printf("%d\n",i);
    printf("%#x\n",i);
    printf("%#x\n",(unsigned short)i);

}