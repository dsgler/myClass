#include <stdio.h>

int main(int argLen,char *argArr[]){
    for (int i=0;i<argLen;i++){
        printf("第%d个参数为：%s\n",i,argArr[i]);
    }
}