#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "user.h"
int main()
{
	Queue a_queue;
	init(&a_queue);
	int i, choice;
	int* p;
	int a[100];
	float b[100];
	char c[100];

	printf("********************************\n");
	printf("*         1.����������         *\n");
	printf("*         2.���渡����         *\n");
	printf("*         3.�����ַ���         *\n");
	printf("********************************\n");

	do
	{
		printf("����������ѡ��: ");
		scanf("%d", &choice);
		int* p = NULL;

		switch (choice) {
		case 1:
			printf("������Ҫ��������ݸ�����");
			scanf("%d", &i);
			printf("�����%d������������: ", i);
			for (int n = 0; n < i; n++) {
				scanf("%d", &a[n]);
				enter(&a_queue, &a[n]);
			}
			printf("�����Ͷ���:");
			for (int n = 0; n < i; n++) {
				int* p = (int*)out(&a_queue);
				printf("%d ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		case 2:
			printf("������Ҫ��������ݸ�����");
			scanf("%d", &i);
			printf("�����%d������������: ", i);
			for (int n = 0; n < i; n++) {
				scanf("%f", &b[n]);
				enter(&a_queue, &b[n]);
			}
			printf("�����Ͷ���:");
			for (int n = 0; n < i; n++) {
				float* p = (float*)out(&a_queue);
				printf("%f ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		case 3:
			printf("������Ҫ��������ݸ�����");
			scanf("%d", &i);
			printf("�����%d������������: ", i);
			getchar();  // �����з�
			for (int n = 0; n < i; n++) {
				scanf(" %c", &c[n]);
				enter(&a_queue, &c[n]);
			}
			printf("�ַ��Ͷ���:");
			for (int n = 0; n < i; n++) {
				char* p = (char*)out(&a_queue);
				printf("%c ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		default:
			printf("��Чѡ�����������롣\n");
			break;
		}
	} while (choice != 3);
	return 0;
}