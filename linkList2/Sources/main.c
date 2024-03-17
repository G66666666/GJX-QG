#define _CRT_SECURE_NO_WARNINGS   //用宏定义来禁用scanf警告
#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 主程序
int main() {
    //    LinkedList *userList = createLinkedList();
    Node* head = renewlist();
    Node* slow;
    Node* fast;
    int choice, data, num, index;

    do {
        printf("********************************                ********************************\n");
        printf("*         1.初始化链表         *                *         2.插入新节点         *\n");
        printf("*         3.反转链表           *                *         4.输出链表           *\n");
        printf("*         5.中间链表           *  11.退出系统   *         6.判断是否成环       *\n");
        printf("*         7.删除节点           *                *         8.奇偶反转           *\n");
        printf("*         9.查询链表           *                *         10.构造循环链表      *\n");
        printf("********************************                ********************************\n");

        //printf("********************************\n");
        //printf("*         1.初始化链表         *\n");
        //printf("*         2.插入新节点         *\n");
        //printf("*         3.反转链表           *\n");
        //printf("*         4.输出链表           *\n");
        //printf("*         5.中间链表           *\n");
        //printf("*         6.判断是否成环       *\n");
        //printf("*         7.删除节点           *\n");
        //printf("*         8.奇偶反转           *\n");
        //printf("*         9.查询链表           *\n");
        //printf("*         10.构造循环链表      *\n");
        //printf("*         11.退出系统          *\n");
        //printf("********************************\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = renewlist();
            printf("链表初始化成功\n");
            print(head);
            break;
        case 2:
            printf("请输入要插入的结点数据：");
            scanf("%d", &data);
            add(&head, data);
            printf("结点插入成功！\n");
            break;
        case 3:
            head = reverse(head);
            printf("链表反转成功\n");
            break;
        case 4:
            print(head);
            break;
        case 5:
            slow = head;
            fast = head;
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast == NULL) {
                printf("链表长度为偶数，中间节点为: %d\n", slow->data);
            }
            else {
                printf("链表长度为奇数，中间节点为: %d\n", slow->data);
            }
            break;
        case 6:
            if (iscycle(head)) {
                printf("链表成环\n");
            }
            else {
                printf("链表不成环\n");
            }
            break;
        case 7:
            printf("请输入要删除的结点数据：");
            scanf("%d", &num);
            head = deletenode(head, num);
            printf("结点删除成功！\n");
            break;
        case 8:
            head = Reverse(head);
            printf("链表奇偶反转成功\n");
            break;
        case 9:
            printf("请输入要查询的结点值:");
            scanf("%d", &num);
            if (search(head, num)) {
                printf("%d在链表中\n", num);
            }
            else {
                printf("%d不在链表中\n", num);
            }
            break;
        case 10:
            printf("请输入要构造循环链表的节点索引值（从1开始）：");
            scanf("%d", &index);
            head = circulate(head, index);
            printf("循环链表构造成功\n");
            break;
        case 11:
            printf("谢谢使用，再见！\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    } while (choice != 11);
    freelist(head);
    return 0;
}