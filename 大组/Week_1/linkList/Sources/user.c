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

// 在链表末尾插入用户节点： 
void add(Linklist* pList, User user)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->user = user;
    newnode->next = NULL;
    Node* last = pList->head;  //遍历 
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

//遍历链表并打印用户信息： 
void print(Linklist* pList)
{
    Node* last = pList->head;
    printf("用户列表：\n");
    while (last != NULL) {
        printf("用户名：%s, 密码：%s\n", last->user.name, last->user.num);
        last = last->next;
    }
}

//释放内存： 
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