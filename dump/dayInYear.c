#include<stdio.h>

struct web{
    char url[128];
    char fullName[64];
    char shortName[32];
};

int strcmp(char* s1,char* s2){
    int i=0;
    while (1){
        if (s1[i]=='\0' && s2[i]=='\0'){
            return 0;
        }

        if (s1[i]==s2[i]){
            i++;
            continue;
        }
        if (s1[i] < s2[i]){
            return -1;
        }else{
            return 1;
        }
    }
}

void swap(struct web webs[],int i,int j){
    struct web tmp=webs[i];
    webs[i]=webs[j];
    webs[j]=tmp;
}

int main()
{
    struct web webs[3];
    const int len=3;
    for (int i=0;i<len;i++){
        struct web w;
        scanf("%127s %63s %31s",w.url,w.shortName,w.fullName);
        webs[i]=w;
    }

    char queryByShortName[32];
    scanf("%31s",queryByShortName);

    //手动冒泡排序，不想再写一遍了
    if (strcmp(webs[0].shortName,webs[1].shortName)==1){
        swap(webs,0,1);
    }
    if (strcmp(webs[1].shortName,webs[2].shortName)==1){
        swap(webs,1,2);
    }
    if (strcmp(webs[0].shortName,webs[1].shortName)==1){
        swap(webs,0,1);
    }

    int queryUrlIndex;
    for (int i=0;i<len;i++){
        struct web w=webs[i];
        printf("%s %s %s\n",w.url,w.shortName,w.fullName);
        if (strcmp(queryByShortName,w.shortName)==0){
            queryUrlIndex=i;
        }
    }
    printf("%s",webs[queryUrlIndex].url);






    return 0;
}