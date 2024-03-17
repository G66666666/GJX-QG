#ifndef USER_H
#define USER_H
//����������ṹ�壺 
typedef struct _node {
	int data;
	struct _node* next;  //ָ����ָ��struct _node���͵�ָ�� 
}Node;

//��������ṹ�壺 
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