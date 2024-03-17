#ifndef USER_H
#define USER_H

//����˫��������ṹ�壺 
typedef struct _node {
	int data;
	struct _node* next;  //ָ����ָ��struct _node���͵���һ��ָ�� 
	struct _node* pre;  //ָ����ָ��struct _node���͵�ǰһ��ָ��
}Node;

//����˫������ṹ�壺 
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