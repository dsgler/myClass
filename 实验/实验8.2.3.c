#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch;

    if (argc != 2)
    {
        printf("Arguments error!\n");
        exit(-1);
    }

    // 使用 freopen 函数重定向标准输入流到指定文件
    if (freopen(argv[1], "r", stdin) == NULL)
    {
        printf("Can't open %s file!\n", argv[1]);
        exit(-1);
    }

    // 从标准输入流读取字符并输出到显示器
    while ((ch = getchar()) != EOF)
        putchar(ch);

    // 关闭标准输入流
    fclose(stdin);

    return 0;
}