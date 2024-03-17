#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ������
Node* renewlist()
{
    return NULL;
}

// ������ĩβ�����½�㣺 
void add(Node** head, int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        /*�������ͷָ�� *head �Ƿ�Ϊ�գ����Ϊ�գ����ʾ�����л�
        û�н�㣬���½������Ϊ����ĵ�һ�����*/
        *head = newnode;  //���½ڵ㸳ֵ��ͷָ��*head
    }
    else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }  //ѭ����������ֱ���ҵ����һ�����
        last->next = newnode;
    }
}

// ��ת����
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }  //������Ϊ�յ��жϣ�������Ϊ��ʱֱ�ӷ���NULL
    Node* p = NULL;
    Node* last = head;
    Node* next = NULL;
    while (last != NULL) {
        next = last->next;
        last->next = p;  //����ǰ���ָ��ǰһ����㣬ʵ�ַ�ת
        p = last;  //����ǰһ�����ָ��pָ��ǰ���
        last = next;  //����ǰ���ָ���ƶ�����һ����㣬��������
    }
    return p;  //���ط�ת����µ�ͷ���
}

//����������ӡ���� 
void print(Node* head)
{
    Node* last = head;  //��ʼ��Ϊ ͷ���
    printf("�������ݣ�\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->next;
    }
    printf("\n");
}

//��ѯ����
int search(Node* head, int num)
{
    Node* last = head;  //��ʼ��Ϊ ͷ���
    while (last != NULL) {
        if (last->data == num) {
            return 1;  //���������ҵ����� 
        }
        last = last->next;
    }
    return 0;  //���������Ҳ������� 
}

//ɾ����㣺
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

//�ж��Ƿ�ɻ���
int iscycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
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
        //������λ�ý���ָ��ָ����һ������λ�ý�㣬�൱��ɾ����ǰż��λ�ý�㡣 
        even = even->next;
    }
    odd->next = evenhead;
    //������λ�ýڵ��ĩβ���ӵ�ż��λ�ýڵ���ʼλ�ã������ż�ڵ�ķ�ת��
    return head;
}

// ����ѭ������
Node* circulate(Node* head, int index) {
    if (index < 1) {
        return head;
    }
    Node* last = head;
    Node* newnode = NULL;  // ��ʼ��newnode
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

//�ͷ��ڴ棺 
void freelist(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(head);
}