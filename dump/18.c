#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[128];
    double ave;
    int id, score1, score2, score3, score4;
    struct student *next;
};

int n;
struct student *head;

void func1()
{
    scanf("%d", &n);

    head = (struct student *)malloc(sizeof(struct student));
    struct student *last = NULL;

    for (int i = 0; i < n; i++)
    {
        if (last == NULL)
        {
            scanf("%d %s %d %d %d %d", &head->id, head->name, &head->score1, &head->score2, &head->score3, &head->score4);
            head->next = NULL;
            double ave = (head->score1 + head->score2 + head->score3 + head->score4) / 4.0;
            head->ave = ave;
            last = head;
            continue;
        }

        struct student *s = (struct student *)malloc(sizeof(struct student));
        scanf("%d %s %d %d %d %d", &s->id, s->name, &s->score1, &s->score2, &s->score3, &s->score4);
        s->next = NULL;
        double ave = (s->score1 + s->score2 + s->score3 + s->score4) / 4.0;
        s->ave = ave;
        last->next = s;
        last = s;
    }

    printf("完成了%d位同学的成绩输入。\n", n);
}

void func2()
{
    struct student *cur = head;
    while (cur != NULL)
    {
        printf("%d %s %d %d %d %d\n", cur->id, cur->name, cur->score1, cur->score2, cur->score3, cur->score4);
        cur = cur->next;
    }
}

void func3()
{
    int id;
    int opt;

    scanf("%d %d", &id, &opt);

    struct student *cur = head;
    while (cur != NULL)
    {
        if (cur->id != id)
        {
            cur = cur->next;
            continue;
        }

        switch (opt)
        {
        case 0:
            scanf("%s", cur->name);
            break;
        case 1:
            scanf("%d", &cur->score1);
            break;
        case 2:
            scanf("%d", &cur->score2);
            break;
        case 3:
            scanf("%d", &cur->score3);
            break;
        case 4:
            scanf("%d", &cur->score4);
            break;
        default:
            // printf("没有这个选项\n");
            1 + 1;
        }

        printf("%d %s %d %d %d %d\n", cur->id, cur->name, cur->score1, cur->score2, cur->score3, cur->score4);
        return;
    }

    // printf("找不到该学生\n")；
}

void func4()
{
    struct student *cur = head;
    while (cur != NULL)
    {
        // double ave=(cur->score1 + cur->score2 + cur->score3 + cur->score4) / 4.0;
        // cur->ave=ave;
        printf("%d %s %.2f\n", cur->id, cur->name, cur->ave);
        cur = cur->next;
    }
}

void func5()
{
    struct student *cur = head;
    while (cur != NULL)
    {
        int sum = cur->score1 + cur->score2 + cur->score3 + cur->score4;
        cur->ave=sum/4.0;
        printf("%d %s %d %.2f\n", cur->id, cur->name, sum, cur->ave);
        cur = cur->next;
    }
}

void func6()
{
    for (int i = n - 1; i > 0; i--)
    {
        struct student *last = NULL;
        struct student *cur = head;
        struct student *next = cur->next;

        int j = i;
        while (j > 0)
        {
            if (cur->ave <= next->ave)
            {
                j--;
                last=cur;
                cur=cur->next;
                next=cur->next;
                continue;
            }

            cur->next = next->next;
            next->next = cur;
            if (last != NULL)
            {
                last->next = next;
            }
            else
            {
                head = next;
            }
            // cur=cur;
            last = next;
            next = cur->next;
            j--;
        }
    }
    
    
    struct student *cur = head;
    while (cur != NULL)
    {
        // int sum = cur->score1 + cur->score2 + cur->score3 + cur->score4;
        printf("%d %s %.2f\n", cur->id, cur->name,  cur->ave);
        cur = cur->next;
    }
}

int main()
{
    int opt;

    while (1)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            // printf("（退出）");
            return 0;
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
        case 5:
            func5();
            break;
        case 6:
            func6();
            break;
        default:
            printf("没有这个选项:%d", opt);
            return -1;
        }
    }
}