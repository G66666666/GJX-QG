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
	printf("*         1.储存整数型         *\n");
	printf("*         2.储存浮点型         *\n");
	printf("*         3.储存字符型         *\n");
	printf("********************************\n");

	do
	{
		printf("请输入您的选择: ");
		scanf("%d", &choice);
		int* p = NULL;

		switch (choice) {
		case 1:
			printf("请输入要储存的数据个数：");
			scanf("%d", &i);
			printf("请输出%d个整数型数据: ", i);
			for (int n = 0; n < i; n++) {
				scanf("%d", &a[n]);
				enter(&a_queue, &a[n]);
			}
			printf("整数型队列:");
			for (int n = 0; n < i; n++) {
				int* p = (int*)out(&a_queue);
				printf("%d ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		case 2:
			printf("请输入要储存的数据个数：");
			scanf("%d", &i);
			printf("请输出%d个整数型数据: ", i);
			for (int n = 0; n < i; n++) {
				scanf("%f", &b[n]);
				enter(&a_queue, &b[n]);
			}
			printf("浮点型队列:");
			for (int n = 0; n < i; n++) {
				float* p = (float*)out(&a_queue);
				printf("%f ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		case 3:
			printf("请输入要储存的数据个数：");
			scanf("%d", &i);
			printf("请输出%d个整数型数据: ", i);
			getchar();  // 处理换行符
			for (int n = 0; n < i; n++) {
				scanf(" %c", &c[n]);
				enter(&a_queue, &c[n]);
			}
			printf("字符型队列:");
			for (int n = 0; n < i; n++) {
				char* p = (char*)out(&a_queue);
				printf("%c ", *p);
				enter(&a_queue, p);
			}
			printf("\n");
			free(p);
			break;
		default:
			printf("无效选择，请重新输入。\n");
			break;
		}
	} while (choice != 3);
	return 0;
}