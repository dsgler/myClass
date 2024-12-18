#include <stdio.h>

int main(){
    '\'' ;
    'x';
    char ch1='0xa';
    'abc';
    'a';
    '\141';
    0141;
    constexpr long long c=((long long)'a'<<16) + ((long long)'b'<<8) + (long long)'c';
    char ch2='\18';
    '\n';
    'n';
    char ch3=18;
    '\057';
    '\a';
    057;
    const int x=10;
    const int * const p=&x;
    printf("%d %d %d",c,ch2,ch3);
}