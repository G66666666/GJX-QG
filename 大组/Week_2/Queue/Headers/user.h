#ifndef USER_H
#define USER_H
//����ṹ��
typedef struct Node  //�ڵ�ṹ��
{
	void* data;  //ʹ��voidָ����Ϊ������������
	struct Node* next;
}Node;

typedef struct  //���нṹ��
{
	Node* front;  //����ָ��
	Node* rear;  //��βָ��
}Queue;

void init(Queue* queue);
void enter(Queue* queue, void* data);
void* out(Queue* queue);

#endif