#ifndef USER_H
#define USER_H
//定义链表结点结构体： 
typedef struct _node {
	int data;
	struct _node* next;  //指针域：指向struct _node类型的指针 
}Node;

//定义链表结构体： 
typedef struct _list {
	Node* head;
}Linklist;

Node* renewlist();
void add(Node** head, int data);
Node* reverse(Node* head);
void print(Node* head);
int search(Node* head, int num);
Node* deletenode(Node* head, int num);
int iscycle(Node* head);
Node* Reverse(Node* head);
Node* circulate(Node* head, int index);
void freelist(Node* head);
#endif