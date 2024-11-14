#include<stdio.h>  

struct student{
    char name[64];
    int score;
};

struct student students[100];
int students_size=0;

void func1(){
    scanf("%d",&students_size);

    for (int i=0;i<students_size;i++){
        struct student s;
        scanf("%s %d",s.name,&s.score);
        students[i]=s;
    }

    printf("%d records were input!\n",students_size);

}

void swap(int i,int j){
    struct student tmp=students[i];
    students[i]=students[j];
    students[j]=tmp;
}

void func2(){
    for (int i=students_size-1;i>0;i--){
        for (int j=0;j<i;j++){
            if (students[j].score<students[j+1].score){
                swap(j,j+1);
            }
        }
    }

    printf("Reorder finished!\n");
}

void func3(){
    for (int i=0;i<students_size;i++){
        printf("%s %d\n",students[i].name,students[i].score);
    }
}

void func4(){
    int query;
    scanf("%d",&query);

    int l=0;
    int r=students_size-1;

    int posi=-1;

    while (l<=r){
        int m=l+(r-l)/2;

        int sco=students[m].score;
        if (sco==query){
            posi=m;
            break;
        }else if(sco<query){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    
    if (posi==-1){
        printf("not found!");
        return;
    }

    for (l=posi;l>=1 && students[l].score==students[l-1].score;l--) ;
    for (r=posi;r<students_size-1 && students[r].score==students[r+1].score;r++) ;
    for (;l<=r;l++){
        printf("%s %d\n",students[l].name,students[l].score);
    }
}

int main(){
    int func;
    while ((scanf("%d",&func)==1) && func>=0 && func <=4){
        switch (func){
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            default:
                //printf("Reorder finished!");
                return 0;
        }
    }
}