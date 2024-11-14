#include<stdio.h>   
  
int main(){  
    int flag=0;  
    for (int i=100;i<1000;i++){  
        int doub=i*i;  
        int left=doub/1000;  
        left=left*1000;  
        left=doub-left;  
        if (left==i){  
            // if (flag==0){  
            //     flag=1;  
            // }else{  
            //     printf("\n");  
            // }  
            printf("\n");  
            printf("%d",i);  
        }  
    }  
}  