#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化双向链表：
Doublelinklist* renewlist()
{
    Doublelinklist* list = (Doublelinklist*)malloc(sizeof(Doublelinklist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// 在链表末尾插入新结点： 
void add(Doublelinklist* list, int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = list->tail;  //将新结点的pre指针指向当前链表的尾部节点
    if (list->head == NULL) {
        list->head = newnode;  //将新节点赋值给头指针list->head
    }
    else {
        list->tail->next = newnode;
    }
    list->tail = newnode;
}

// 反转链表： 
void reverse(Doublelinklist* list)
{
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }  //对链表为空的判断：当链表为空时直接返回NULL
    Node* last = list->head;
    Node* pre = NULL;
    Node* next = NULL;
    while (last != NULL) {
        next = last->next;
        last->next = pre;  //将当前结点指向前一个结点，实现反转
        pre = last;  //更新前一个结点指针p指向当前结点
        last = next;  //将当前结点指针移动到下一个结点，继续遍历
    }
    list->tail = list->head;
    list->head = pre;
}

//遍历双向链表并打印链表： 
void print(Doublelinklist* list)
{
    Node* last = list->head;  //初始化为 头结点
    printf("链表内容：\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->next;
    }
    printf("\n");
}

//查询中间链表：
Node* middle(Doublelinklist* list)
{
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }  //用两个指针的不同速度来遍历链表
    return slow;  //返回链表的中间节点 
}

//查询链表：
int search(Doublelinklist* list, int num)
{
    Node* last = list->head;  //初始化为 头结点
    while (last != NULL) {
        if (last->data == num) {
            return 1;  //在链表中找到数据 
        }
        last = last->next;
    }
    return 0;  //在链表中找不到数据 
}

//删除结点：
void deletenode(Doublelinklist* list, int num)
{
    Node* last = list->head;
    while (last != NULL) {
        if (last->data == num) {
            if (last == list->head) {  //删除的节点是头结点
                list->head = last->next;
                if (list->head != NULL) {
                    list->head->pre = NULL;
                }
            }
            else if (last == list->tail) {  //删除的节点是尾节点 
                list->tail = last->pre;
                list->tail->next = NULL;
            }
            else {  //删除的节点在链表中间 
                last->pre->next = last->next;
                last->next->pre = last->pre;
            }
            free(last);  //释放要删除的节点所占用的内存空间
            break;
        }
        last = last->next;
    }
}
//疑问：当用户输入的数据不在链表里时，怎么打印出“未找到要删除的结点”？？？？ 

//判断是否成环：
int iscycle(Doublelinklist* list)
{
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  //慢指针 slow 移动一步
        fast = fast->next->next;  //快指针 fast 移动两步
        if (slow == fast) {
            //判断慢指针和快指针是否相遇，如果相遇，则说明链表存在环
            return 1; //成环 
        }
    }
    return 0; // 无环
}

//奇偶反转链表:
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
        //将奇数位置结点的指针指向下一个奇数位置结点，相当于删除当前偶数位置结点。 
        even = even->next;
    }
    odd->next = evenhead;
    //将奇数位置节点的末尾连接到偶数位置节点起始位置，完成奇偶节点的反转。
}

// 构造循环链表
void circulate(Doublelinklist* list)
{
    if (list->head == NULL) {
        return;
    }
    list->tail->next = list->head;  //尾节点的下一个指针指向头节点
    list->head->pre = list->tail;  //头节点的前一个指针指向尾节点
}

//释放内存： 
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