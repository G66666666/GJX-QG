#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

Linklist* create()
{
    Linklist* list = (Linklist*)malloc(sizeof(Linklist));
    list->head = NULL;
    //	list->len=0;
    return list;
}

// ������ĩβ�����û��ڵ㣺 
void add(Linklist* pList, User user)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->user = user;
    newnode->next = NULL;
    Node* last = pList->head;  //���� 
    if (last != NULL) {
        while (last->next) {
            last = last->next;
        }
        last->next = newnode;
    }
    else {
        pList->head = newnode;
    }
}

//����������ӡ�û���Ϣ�� 
void print(Linklist* pList)
{
    Node* last = pList->head;
    printf("�û��б�\n");
    while (last != NULL) {
        printf("�û�����%s, ���룺%s\n", last->user.name, last->user.num);
        last = last->next;
    }
}

//�ͷ��ڴ棺 
void freelist(Linklist* pList) {
    Node* current = pList->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(pList);
    printf("Memory freed. Exiting program.\n");
}