#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user.h"
//创建一个栈
LinkStack* create()
{
    LinkStack* linkstack = (LinkStack*)malloc(sizeof(LinkStack));
    linkstack->top = NULL;
    return linkstack;
}
//数据入栈
void push(LinkStack* s, char data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}
//检查栈是否为空：确保在执行pop()等操作前，栈中确实存在元素
int isnull(LinkStack* s)
{
    return s->top == NULL ? 1 : 0;
}
//数据出栈
char pop(LinkStack* s)
{
    if (s->top == NULL) {
        return 0;
    }
    Node* p = s->top;
    char data = p->data;  //将要删除的数据放在临时指针上，方便实现出栈
    s->top = p->next;  //将顶指针向下一位置移动
    free(p);  //释放p，即数据出栈
    return data;
}
//返回栈顶的值
char get(LinkStack* s)
{
    if (s->top == NULL) {
        return '\0';
    }  //为空栈，无元素
    return s->top->data;
}
//判断运算符号的优先级
int priority(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}
//把中缀表达式转化为后缀表达式（infix为中缀表达式，postfix为后缀表达式）
void convert(char* infix, char* postfix)
{
    LinkStack* s = create();  //创建一个栈
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];  //若遇到数字或字母，将其放在后缀表达式中
        }
        else if (infix[i] == '(') {
            push(s, infix[i]);  //若遇到左括号，将其压入栈
        }
        else if (infix[i] == ')') {
            while (get(s) != '(') {
                postfix[j++] = pop(s);  //遇到右括号
            }
            pop(s);
        }
        else if (priority(infix[i])) {
            while (!isnull(s) && priority(get(s)) >= priority(infix[i])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
        i++;
    }
    while (!isnull(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}
//把后缀表达式进行运算得出结果
double evaluate(char* postfix)
{
    LinkStack* s = create();  //初始化栈
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(s, postfix[i] - '0');  //若是数字，表示其值
        }
        else {  //若是符号，按优先级进行出栈或入栈
            double b = pop(s);  //栈顶元素先出
            double a = pop(s);  //第二个元素后出
            switch (postfix[i]) {
            case '+':
                push(s, a + b);
                break;
            case '-':
                push(s, a - b);
                break;
            case '*':
                push(s, a * b);
                break;
            case '/':
                push(s, a / b);
                break;
            }
        }
    }
    double result = pop(s);
    free(s->top);  //释放结点
    free(s);  //释放栈
    return result;
}