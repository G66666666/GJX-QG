#include <stdio.h>
#include <stdlib.h>
#include "user.h"
//��ʼ������
void init(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}
//��Ӳ���
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
//���Ӳ���
void* out(Queue* queue)
{
	if (queue->front == NULL) {  //�ն���
		return NULL;
	}
	Node* p = queue->front;  //������ʱָ��
	void* data = p->data;
	queue->front = queue->front->next;
	free(p);  //�ͷ�p����Ԫ�س���
	if (queue->front == NULL) {
		queue->rear == NULL;
	}
	return data;
}