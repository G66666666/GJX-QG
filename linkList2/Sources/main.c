#define _CRT_SECURE_NO_WARNINGS   //�ú궨��������scanf����
#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������
int main() {
    //    LinkedList *userList = createLinkedList();
    Node* head = renewlist();
    Node* slow;
    Node* fast;
    int choice, data, num, index;

    do {
        printf("********************************                ********************************\n");
        printf("*         1.��ʼ������         *                *         2.�����½ڵ�         *\n");
        printf("*         3.��ת����           *                *         4.�������           *\n");
        printf("*         5.�м�����           *  11.�˳�ϵͳ   *         6.�ж��Ƿ�ɻ�       *\n");
        printf("*         7.ɾ���ڵ�           *                *         8.��ż��ת           *\n");
        printf("*         9.��ѯ����           *                *         10.����ѭ������      *\n");
        printf("********************************                ********************************\n");

        //printf("********************************\n");
        //printf("*         1.��ʼ������         *\n");
        //printf("*         2.�����½ڵ�         *\n");
        //printf("*         3.��ת����           *\n");
        //printf("*         4.�������           *\n");
        //printf("*         5.�м�����           *\n");
        //printf("*         6.�ж��Ƿ�ɻ�       *\n");
        //printf("*         7.ɾ���ڵ�           *\n");
        //printf("*         8.��ż��ת           *\n");
        //printf("*         9.��ѯ����           *\n");
        //printf("*         10.����ѭ������      *\n");
        //printf("*         11.�˳�ϵͳ          *\n");
        //printf("********************************\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = renewlist();
            printf("�����ʼ���ɹ�\n");
            print(head);
            break;
        case 2:
            printf("������Ҫ����Ľ�����ݣ�");
            scanf("%d", &data);
            add(&head, data);
            printf("������ɹ���\n");
            break;
        case 3:
            head = reverse(head);
            printf("����ת�ɹ�\n");
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
                printf("������Ϊż�����м�ڵ�Ϊ: %d\n", slow->data);
            }
            else {
                printf("������Ϊ�������м�ڵ�Ϊ: %d\n", slow->data);
            }
            break;
        case 6:
            if (iscycle(head)) {
                printf("����ɻ�\n");
            }
            else {
                printf("�����ɻ�\n");
            }
            break;
        case 7:
            printf("������Ҫɾ���Ľ�����ݣ�");
            scanf("%d", &num);
            head = deletenode(head, num);
            printf("���ɾ���ɹ���\n");
            break;
        case 8:
            head = Reverse(head);
            printf("������ż��ת�ɹ�\n");
            break;
        case 9:
            printf("������Ҫ��ѯ�Ľ��ֵ:");
            scanf("%d", &num);
            if (search(head, num)) {
                printf("%d��������\n", num);
            }
            else {
                printf("%d����������\n", num);
            }
            break;
        case 10:
            printf("������Ҫ����ѭ������Ľڵ�����ֵ����1��ʼ����");
            scanf("%d", &index);
            head = circulate(head, index);
            printf("ѭ��������ɹ�\n");
            break;
        case 11:
            printf("ллʹ�ã��ټ���\n");
            break;
        default:
            printf("��Чѡ�����������롣\n");
            break;
        }
    } while (choice != 11);
    freelist(head);
    return 0;
}