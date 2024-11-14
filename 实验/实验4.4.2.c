#include <stdio.h>

#define CHANGE 0

int main(){
    char str[1024];
    int len=sizeof(str)/sizeof(char);
    printf("请输入一串无空格和换行的英文\n");
    scanf("%s",str);

#if (CHANGE==1)
    int gap='A'-'a';
    for (int i=0;str[i]!='\0' && i<len;i++){
        char ch=str[i];
        if (ch>='a'&& ch<='z'){
            str[i]=ch+gap;
        }else if(ch >= 'A' && ch<= 'Z'){
            str[i]=ch-gap;
        }
    }
#endif
    printf("%s\n",str);
}