#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ��˫������
Doublelinklist* renewlist()
{
    Doublelinklist* list = (Doublelinklist*)malloc(sizeof(Doublelinklist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// ������ĩβ�����½�㣺 
void add(Doublelinklist* list, int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = list->tail;  //���½���preָ��ָ��ǰ�����β���ڵ�
    if (list->head == NULL) {
        list->head = newnode;  //���½ڵ㸳ֵ��ͷָ��list->head
    }
    else {
        list->tail->next = newnode;
    }
    list->tail = newnode;
}

// ��ת���� 
void reverse(Doublelinklist* list)
{
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }  //������Ϊ�յ��жϣ�������Ϊ��ʱֱ�ӷ���NULL
    Node* last = list->head;
    Node* pre = NULL;
    Node* next = NULL;
    while (last != NULL) {
        next = last->next;
        last->next = pre;  //����ǰ���ָ��ǰһ����㣬ʵ�ַ�ת
        pre = last;  //����ǰһ�����ָ��pָ��ǰ���
        last = next;  //����ǰ���ָ���ƶ�����һ����㣬��������
    }
    list->tail = list->head;
    list->head = pre;
}

//����˫��������ӡ���� 
void print(Doublelinklist* list)
{
    Node* last = list->head;  //��ʼ��Ϊ ͷ���
    printf("�������ݣ�\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->next;
    }
    printf("\n");
}

//��ѯ�м�����
Node* middle(Doublelinklist* list)
{
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }  //������ָ��Ĳ�ͬ�ٶ�����������
    return slow;  //����������м�ڵ� 
}

//��ѯ����
int search(Doublelinklist* list, int num)
{
    Node* last = list->head;  //��ʼ��Ϊ ͷ���
    while (last != NULL) {
        if (last->data == num) {
            return 1;  //���������ҵ����� 
        }
        last = last->next;
    }
    return 0;  //���������Ҳ������� 
}

//ɾ����㣺
void deletenode(Doublelinklist* list, int num)
{
    Node* last = list->head;
    while (last != NULL) {
        if (last->data == num) {
            if (last == list->head) {  //ɾ���Ľڵ���ͷ���
                list->head = last->next;
                if (list->head != NULL) {
                    list->head->pre = NULL;
                }
            }
            else if (last == list->tail) {  //ɾ���Ľڵ���β�ڵ� 
                list->tail = last->pre;
                list->tail->next = NULL;
            }
            else {  //ɾ���Ľڵ��������м� 
                last->pre->next = last->next;
                last->next->pre = last->pre;
            }
            free(last);  //�ͷ�Ҫɾ���Ľڵ���ռ�õ��ڴ�ռ�
            break;
        }
        last = last->next;
    }
}
//���ʣ����û���������ݲ���������ʱ����ô��ӡ����δ�ҵ�Ҫɾ���Ľ�㡱�������� 

//�ж��Ƿ�ɻ���
int iscycle(Doublelinklist* list)
{
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  //��ָ�� slow �ƶ�һ��
        fast = fast->next->next;  //��ָ�� fast �ƶ�����
        if (slow == fast) {
            //�ж���ָ��Ϳ�ָ���Ƿ������������������˵��������ڻ�
            return 1; //�ɻ� 
        }
    }
    return 0; // �޻�
}

//��ż��ת����:
void Reverse(Doublelinklist* list)
{
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }
    Node* odd = list->head;
    Node* even = list->head->next;
    Node* evenhead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        //������λ�ý���ָ��ָ����һ������λ�ý�㣬�൱��ɾ����ǰż��λ�ý�㡣 
        even = even->next;
    }
    odd->next = evenhead;
    //������λ�ýڵ��ĩβ���ӵ�ż��λ�ýڵ���ʼλ�ã������ż�ڵ�ķ�ת��
}

// ����ѭ������
void circulate(Doublelinklist* list)
{
    if (list->head == NULL) {
        return;
    }
    list->tail->next = list->head;  //β�ڵ����һ��ָ��ָ��ͷ�ڵ�
    list->head->pre = list->tail;  //ͷ�ڵ��ǰһ��ָ��ָ��β�ڵ�
}

//�ͷ��ڴ棺 
void freelist(Doublelinklist* list)
{
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}