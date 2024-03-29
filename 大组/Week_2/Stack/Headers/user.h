#ifndef USER_H
#define USER_H

//��ջ�Ľṹ 
typedef struct Node  //������ 
{
    char data;
    struct Node* next;
}Node;

typedef struct LinkStack  //���嶥ָ�� 
{
    Node* top;
}LinkStack;

LinkStack* create();
void push(LinkStack* s, char data);
int isnull(LinkStack* s);
char pop(LinkStack* s);
char get(LinkStack* s);
int priority(char c);
void convert(char* infix, char* postfix);
double evaluate(char* postfix);

#endif#pragma once
