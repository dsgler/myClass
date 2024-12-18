#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// 栈结构
typedef struct {
    int top;
    char items[MAX];
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 检查栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 检查栈是否已满
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// 压栈
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

// 出栈
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// 获取栈顶元素
char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

// 检查是否为运算符
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 获取运算符优先级
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 中缀表达式转换为后缀表达式
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch) || isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // 弹出左括号
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}