#ifndef USER_H
#define USER_H

//定义双向链表结点结构体： 
typedef struct _node {
	int data;
	struct _node* next;  //指针域：指向struct _node类型的下一个指针 
	struct _node* pre;  //指针域：指向struct _node类型的前一个指针
}Node;

//定义双向链表结构体： 
typedef struct _list {
	Node* head;
	Node* tail;
}Doublelinklist;

Doublelinklist* renewlist();
void add(Doublelinklist* list, int data);
void reverse(Doublelinklist* list);
void print(Doublelinklist* list);
Node* middle(Doublelinklist* list);
int search(Doublelinklist* list, int num);
void deletenode(Doublelinklist* list, int num);
int iscycle(Doublelinklist* list);
void Reverse(Doublelinklist* list);
void circulate(Doublelinklist* list);
void freelist(Doublelinklist* list);

#endif