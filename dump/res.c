#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[5];
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }

    f(arr,0,n-1);

    printf("%d",arr[0]);
    for (int i=1;i<n;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}

void f(int* arr,int l,int r){
    if (l>=r) return;

    int tmp=arr[l];
    arr[l]=arr[r];
    arr[r]=tmp;

    f(arr,l+1,r-1);
}