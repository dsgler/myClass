#include<stdio.h>

int main(){
    char ch=getchar();
    int i;
    switch (ch){
        case 'A':
            i=10;
            break;
        case 'B':
            i=11;
            break;
        case 'C':
            i=12;
            break;
        case 'D':
            i=13;
            break;
        case 'E':
            i=14;
            break;
        case 'F':
            i=15;
            break;
        default:
            i=ch-'0';
    }
    printf("%d",i);
}