#include<math.h>
#include<stdio.h> 

void YinZi(int arr1[],int arr2[],int n){
    int m=sqrt(n);
    int p=0;
    for (int i=2;i<=m;i++){
        if (n%i==0){
            arr1[p]=i;
            arr2[p]=n/i;
            p++;
        }
    }
    arr1[p]=-1;
    arr2[p]=-1;
}

int arr1[1000];
int arr2[1000];

int isWanQuan(int n){
    YinZi(arr1,arr2,n);
    if (arr1[0]==-1) return 0;

    int sum=1;
    int p=0;
    int isRepete=0;
    while (1){
        if (arr1[p]==-1) break;

        if (arr1[p]==arr2[p]){
            sum+=arr1[p];
            isRepete=1;
            p++;
            break;
        }

        sum+=arr1[p];
        sum+=arr2[p];
        p++;
    }
    //现在p就是长度

    if (sum==n){
        printf("%d=1",n);

        if (isRepete==0){
            for (int k=0;k<p;k++){
                printf("+%d",arr1[k]);
            }
            for (int k=p-1;k>=0;k--){
                printf("+%d",arr2[k]);
            }
        }else{
            for (int k=0;k<p;k++){
                printf("+%d",arr1[k]);
            }
            for (int k=p-2;k>=0;k--){
                printf("+%d",arr2[k]);
            }
        }
        printf("\n");
    }

    
}

int main(){

    for (int i=6;i<10000;i++){
        isWanQuan(i);
    }
}