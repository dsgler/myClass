#include <stdio.h>
#define M 10
#define N 3
int main2(void)
{
    int a[M], b[M]; /* 数组a存放圈中人的编号，数组b存放出圈人的编号 */
    int i, j, k;
    for (i = 0; i < M; i++) /* 对圈中人按顺序编号1—M */
        a[i] = i + 1;
    for (i = M, j = 0; i > 1; i--)
    {
        /* i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置 */
        for (k = 1; k <= N; k++) /* 1至N报数 */
            if (++j > i - 1)
                j = 0;                      /* 最后一个人报数后第一个人接着报，形成一个圈 */
        b[M - i] = j ? a[j - 1] : a[i - 1]; /* 将报数为N的人的编号存入数组b */
        if (j)
            for (k = --j; k < i; k++) /* 压缩数组a，使报数为N的人出圈 */
                a[k] = a[k + 1];
    }
    for (i = 0; i < M - 1; i++) /* 按次序输出出圈人的编号 */
        printf("%6d", b[i]);
    printf("%6d\n", a[0]); /* 输出圈中最后一个人的编号 */
    return 0;
}

int main()
{
    int people[M];
    int position, count;

    // 初始化数组，所有人都在圈内
    for (int i = 0; i < M; i++)
    {
        people[i] = 1;
    }

    position = 0; // 记录位置
    count = 0;    // 记录圈外人数

    while (count < M - 1)
    {
        for (int j = 0; j < N - 1; j++)
        {
            while (people[position] == 0)
            {
                position = (position + 1) % M;
            }
            position = (position + 1) % M;
        }

        while (people[position] == 0)
        {
            position = (position + 1) % M;
        }
        // 第N个人出圈
        printf("%6d", position + 1);
        people[position] = 0;
        count++;
        position = (position + 1) % M;
        while (people[position] == 0)
        {
            position = (position + 1) % M;
        }
    }

    // 找出最后剩下的那个人
    for (position = 0; position < M; position++)
    {
        if (people[position] == 1)
        {
            printf("%6d\n", position + 1);
            break;
        }
    }

    return 0;
}
