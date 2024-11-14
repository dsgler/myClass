#include<stdio.h>
#include<math.h>

double jc(int n){
    double res=1;
    while (n>1){
        res*=n;
        n--;
    }
    return res;
}

int main(){
    int x=7,n=27;
    double sum=0;
    for (int i=0;i<=n;i++){
        sum+=pow(x,i)/jc(i);
    }
    printf("%.6f\n",sum);
}