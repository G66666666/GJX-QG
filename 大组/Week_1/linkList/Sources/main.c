#include "user.h"
#include <stdio.h>

int main()
{
    Linklist* list = create();
    User user;
    int choice;
    do {
        printf("\n�û�����ϵͳ\n");
        printf("1. ����û�\n");
        printf("2. ��ʾ�û��б�\n");
        printf("3. �˳�\n");
        printf("��ѡ�������");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�������û�����");
            scanf_s("%s", user.name);
        out:
            printf("������绰���룺");
            scanf_s("%s", user.num);
            if (strlen(user.num) != 11) {
                printf("��Чѡ�����������롣\n");
                while (getchar() != '\n');  // ������뻺����
                goto out;
            }
            else {
                add(list, user);
                printf("�û���ӳɹ���\n");
            }
            break;
        case 2:
            print(list);
            break;
        case 3:
            printf("ллʹ�ã��ټ���\n");
            break;
        default:
            printf("��Чѡ�����������롣\n");
            break;
        }
    } while (choice != 3);
    freelist(list);  // �������ʱ�ͷ�������ռ�õ��ڴ�
    return 0;
}