#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user.h"
//����һ��ջ
LinkStack* create()
{
    LinkStack* linkstack = (LinkStack*)malloc(sizeof(LinkStack));
    linkstack->top = NULL;
    return linkstack;
}
//������ջ
void push(LinkStack* s, char data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}
//���ջ�Ƿ�Ϊ�գ�ȷ����ִ��pop()�Ȳ���ǰ��ջ��ȷʵ����Ԫ��
int isnull(LinkStack* s)
{
    return s->top == NULL ? 1 : 0;
}
//���ݳ�ջ
char pop(LinkStack* s)
{
    if (s->top == NULL) {
        return 0;
    }
    Node* p = s->top;
    char data = p->data;  //��Ҫɾ�������ݷ�����ʱָ���ϣ�����ʵ�ֳ�ջ
    s->top = p->next;  //����ָ������һλ���ƶ�
    free(p);  //�ͷ�p�������ݳ�ջ
    return data;
}
//����ջ����ֵ
char get(LinkStack* s)
{
    if (s->top == NULL) {
        return '\0';
    }  //Ϊ��ջ����Ԫ��
    return s->top->data;
}
//�ж�������ŵ����ȼ�
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
//����׺���ʽת��Ϊ��׺���ʽ��infixΪ��׺���ʽ��postfixΪ��׺���ʽ��
void convert(char* infix, char* postfix)
{
    LinkStack* s = create();  //����һ��ջ
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];  //���������ֻ���ĸ��������ں�׺���ʽ��
        }
        else if (infix[i] == '(') {
            push(s, infix[i]);  //�����������ţ�����ѹ��ջ
        }
        else if (infix[i] == ')') {
            while (get(s) != '(') {
                postfix[j++] = pop(s);  //����������
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
//�Ѻ�׺���ʽ��������ó����
double evaluate(char* postfix)
{
    LinkStack* s = create();  //��ʼ��ջ
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(s, postfix[i] - '0');  //�������֣���ʾ��ֵ
        }
        else {  //���Ƿ��ţ������ȼ����г�ջ����ջ
            double b = pop(s);  //ջ��Ԫ���ȳ�
            double a = pop(s);  //�ڶ���Ԫ�غ��
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
    free(s->top);  //�ͷŽ��
    free(s);  //�ͷ�ջ
    return result;
}