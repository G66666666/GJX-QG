#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义用户结构体： 
typedef struct _user {
	char name[50];
	char num[12];
}User;

//定义链表结点结构体： 
typedef struct _node {
	User user;
	struct _node* next;  //指针域：指向struct _node类型的指针 
}Node;//,*Linklist;

//定义链表结构体： 
typedef struct _list {
	Node* head;
}Linklist;

Linklist* create();

void add(Linklist* pList, User user);
void print(Linklist* pList);
void freelist(Linklist* pList);

#endif