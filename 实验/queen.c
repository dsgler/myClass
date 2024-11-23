#include <stdio.h>

int crax[2000], cray[2000], cx[2000]; // 用于标记主对角线、副对角线和列是否被占用
int ans[2000]; // 存储每一行皇后放置的列位置
int n, tot; // n 为棋盘大小，tot 为解的总数

// 回溯搜索函数，x 表示当前处理的行号
void search(int x)
{
    if (x > n) {
        tot++; // 如果所有行都已成功放置皇后，解的数量加一
        return;
    }
    for (int y = 1; y <= n; y++) // 遍历每一列
    {
        // 检查当前位置是否安全
        if (crax[x + y]) continue;         // 检查主对角线是否有冲突
        if (cray[x - y + n]) continue;     // 检查副对角线是否有冲突，偏移 n 防止数组下标为负
        if (cx[y]) continue;               // 检查列是否有冲突

        ans[x] = y;            // 记录当前行皇后的位置
        crax[x + y] = 1;       // 标记主对角线被占用
        cray[x - y + n] = 1;   // 标记副对角线被占用
        cx[y] = 1;             // 标记者被占用

        search(x + 1);         // 递归处理下一行

        // 回溯，撤销标记
        crax[x + y] = 0;
        cray[x - y + n] = 0;
        cx[y] = 0;
    }
}

int main(void)
{
    scanf("%d", &n); // 输入棋盘大小
    if (n == 2 || n == 3) // 当 n 为 2 或 3 时，无解
    {
        printf("无解");
        return 0;
    }
    search(1); // 从第一行开始搜索
    printf("%d", tot); // 输出解的总数
    return 0;
}