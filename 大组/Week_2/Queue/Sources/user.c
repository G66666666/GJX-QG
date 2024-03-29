#include <stdio.h>
#include <stdlib.h>
#include "user.h"
//初始化队列
void init(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}
//入队操作
void enter(Queue* queue, void* data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	if (queue->rear == NULL) {
		queue->front = newnode;
	}
	else {
		queue->rear->next = newnode;
	}
	queue->rear = newnode;
}
//出队操作
void* out(Queue* queue)
{
	if (queue->front == NULL) {  //空队列
		return NULL;
	}
	Node* p = queue->front;  //创建临时指针
	void* data = p->data;
	queue->front = queue->front->next;
	free(p);  //释放p，即元素出队
	if (queue->front == NULL) {
		queue->rear == NULL;
	}
	return data;
}