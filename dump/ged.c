#include<stdio.h>
int gcd(int a,int b){

    if (a==b){
        return a;
    }
    if (a<b){
        return gcd(b,a);
    }
    if (a%b==0){
        return b;
    }
    return gcd(b,a%b);

}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int g=gcd(a,b);
    printf("%d %d",g,a/g*b);

    return 0;
}
