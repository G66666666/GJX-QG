#ifndef USER_H
#define USER_H
//定义结构体
typedef struct Node  //节点结构体
{
	void* data;  //使用void指针作为泛型数据类型
	struct Node* next;
}Node;

typedef struct  //队列结构体
{
	Node* front;  //队首指针
	Node* rear;  //队尾指针
}Queue;

void init(Queue* queue);
void enter(Queue* queue, void* data);
void* out(Queue* queue);

#endif