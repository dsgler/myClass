#include<stdio.h> 

int pow(int base,int x){
    if (x==0) return 1;
    if (x==1) return base;
    if (x%2==0){
        int tmp=pow(base,x/2);
        return tmp*tmp;
    }else{
        int tmp=pow(base,x/2);
        return tmp*tmp*base;
    }
}

int isZiMi(int n)
{
    int arr[10];
    int len=0;
    int rate=1;
    
    for (;n/rate>=1;len++,rate*=10){
        int tmp=n/rate;
        tmp%=10;
        arr[len]=tmp;
    }

    int sum=0;
    for (int i=0;i<len;i++){
        sum+=pow(arr[i],len);
    }

    if (sum==n){
        return 1;
    }

    return 0;

}

const char numNames[][64]={"水仙花数","四叶玫瑰数","五角星数","六合数","北斗星数","八仙数"};

int main(){
    int k;
    while ((scanf("%d",&k))==1){
        if (k<3 || k>8) break;

        //int cnt=0;
        int arr[64];
        int pArr=0;

        for (int i=pow(10,k-1),limit=pow(10,k) ; i<limit ; i++){
            if (isZiMi(i)){
                arr[pArr]=i;
                pArr++;
            }
        }

        printf("%d位的%s共有%d个",k,numNames[k-3],pArr);
        int flag=0;
        for (int i=0;i<pArr;i++){
            if (flag==0){
                flag=1;
            }else{
                printf(",");
            }

            printf("%d",arr[i]);
        }
        printf("\n");
    }

    return 0;
}