#include <stdio.h>
#include <math.h>

#define GET_S(x,y,z) ((x+y+z)/2)
#define GET_AREA(s,x,y,z) (sqrt(s*(s-x)*(s-y)*(s-z)))

int main(){
    int x,y,z;
    printf("请输入x,y,z\n");
    scanf("%d %d %d",&x,&y,&z);
    double s=GET_S(x,y,z);
    double area=GET_AREA(s,x,y,z);
    printf("s=%f area=%f\n",s,area);
}