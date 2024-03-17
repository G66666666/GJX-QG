#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化链表：
Node* renewlist()
{
    return NULL;
}

// 在链表末尾插入新结点： 
void add(Node** head, int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        /*检查链表头指针 *head 是否为空，如果为空，则表示链表中还
        没有结点，将新结点设置为链表的第一个结点*/
        *head = newnode;  //将新节点赋值给头指针*head
    }
    else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }  //循环遍历链表，直到找到最后一个结点
        last->next = newnode;
    }
}

// 反转链表
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }  //对链表为空的判断：当链表为空时直接返回NULL
    Node* p = NULL;
    Node* last = head;
    Node* next = NULL;
    while (last != NULL) {
        next = last->next;
        last->next = p;  //将当前结点指向前一个结点，实现反转
        p = last;  //更新前一个结点指针p指向当前结点
        last = next;  //将当前结点指针移动到下一个结点，继续遍历
    }
    return p;  //返回反转后的新的头结点
}

//遍历链表并打印链表： 
void print(Node* head)
{
    Node* last = head;  //初始化为 头结点
    printf("链表内容：\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->next;
    }
    printf("\n");
}

//查询链表：
int search(Node* head, int num)
{
    Node* last = head;  //初始化为 头结点
    while (last != NULL) {
        if (last->data == num) {
            return 1;  //在链表中找到数据 
        }
        last = last->next;
    }
    return 0;  //在链表中找不到数据 
}

//删除结点：
Node* deletenode(Node* head, int num) {
    Node* last = head;
    Node* p = NULL;
    while (last != NULL) {
        if (last->data == num) {
            if (p == NULL) {
                head = last->next;
            }
            else {
                p->next = last->next;
            }
            free(last);
            break;
        }
        p = last;
        last = last->next;
    }
    return head;
}

//判断是否成环：
int iscycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
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
Node* Reverse(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
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
    return head;
}

// 构造循环链表
Node* circulate(Node* head, int index) {
    if (index < 1) {
        return head;
    }
    Node* last = head;
    Node* newnode = NULL;  // 初始化newnode
    int i;
    for (i = 1; i < index; i++) {
        if (last->next == NULL) {
            return head;
        }
        last = last->next;
    }
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = last->data;
    newnode->next = last->next;
    last->next = newnode;
    return head;
}

//释放内存： 
void freelist(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(head);
}