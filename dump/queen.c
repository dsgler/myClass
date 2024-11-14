#include<stdio.h>  
#include<stdbool.h>
#define LEN 10

// 我想面向结果编程
int n;
//bool Pan[LEN][LEN];
int cnt=0;

void copyPan(bool Pan[LEN][LEN],bool Pan2[LEN][LEN]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            Pan2[i][j]=Pan[i][j];
        }
    }
}



bool queen(bool Pan[LEN][LEN],int line){
    if (line==n) {
        cnt++;
        return true;
    }

    bool ok=false;

    int col=0;
    while (col<n){
        // true为不能下
        if (Pan[line][col]==false){
            bool Pan2[LEN][LEN];
            copyPan(Pan,Pan2);

            for (int i=line+1;i<n;i++){
                Pan2[i][col]=true;
            }

            for (int i=line+1,j=col+1;(i<n && j<n);i++,j++){
                Pan2[i][j]=true;
            }

            for (int i=line+1,j=col-1;i<n && j>=0;i++,j--){
                Pan2[i][j]=true;
            }

            ok|=queen(Pan2,line+1);

        }
        col++;
    }
    return ok;
    

}



int main(){
    scanf("%d",&n);

    bool Pan[LEN][LEN]={0};

    queen(Pan,0);

    printf("%d",cnt);
}