#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;  //数据域 
	struct _node *next;  //指针域：指向struct _node类型的指针 
}Node,*Linklist; 

typedef struct _list{
	Node* head;
}List;

void add(List* pList,int num); 
void print(List* pList);

int main(int argc,char const *argv[])
{
	List list;
	list.head=NULL;
	int num;
	do{
		scanf("%d",&num);
		if (num!=-1){
			add(&list, num);
		}
	} while (num!=-1);
	print(&list);
	
	scanf("%d",&num);
	Node* p;
	int isfound=0;
	for (p=list.head;p;p=p->next){
		if (p->data==num){
			printf("找到了\n");
			isfound=1;
			break;
		}
	}
	if (!isfound){
		printf("没找到\n");
	}
	Node* q;
	for (q=NULL,p=list.head;p;q=p,p=p->next){
		if (p->data==num){
			if (q){
				q->next=p->next;
			} else {
				list.head=p->next;
			}
			free(p);
			break;
		}
	}
	//删除链表：
	for (p=list.head;p;p=q){
		q=p->next;
		free(p);
	}
	return 0;
}

//增加链表数据：
void add(List* pList,int num)
{
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=num;
	p->next=NULL;
	Node* last=pList->head;  //遍历 
	if (last!=NULL){
		while (last->next){
			last=last->next;  //从尾结点插入数据 
		}
		last->next=p; 
	} else {
		pList->head=p;
	}
}

//查询链表：
void print(List* pList)
{
	Node* p;
	for (p=pList->head;p;p=p->next){
		printf("%d\t",p->data);
	}
	printf("\n");
}
