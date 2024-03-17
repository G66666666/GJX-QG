#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����û��ṹ�壺 
typedef struct _user {
	char name[50];
	char num[12];
}User;

//����������ṹ�壺 
typedef struct _node {
	User user;
	struct _node* next;  //ָ����ָ��struct _node���͵�ָ�� 
}Node;//,*Linklist;

//��������ṹ�壺 
typedef struct _list {
	Node* head;
}Linklist;

Linklist* create();

void add(Linklist* pList, User user);
void print(Linklist* pList);
void freelist(Linklist* pList);

#endif