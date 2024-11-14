 #include<stdio.h>

 int main(){
    char all[256];

    char ch;
    int i=0;
    char last='\0';
    while ((ch=getchar())!='!'){
        if (last==' ' && ch==' ') continue;

        if (ch==' ') {
            last=' ';
        }
        if (last==' ' && ch!=' '){
            last=ch;
        }

        all[i]=ch;
        i++;
    }
    all[i]='!';
    all[i+1]='\0';

    printf("%s",all);
 }