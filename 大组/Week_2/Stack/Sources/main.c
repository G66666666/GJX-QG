#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user.h"
int main()
{
    char infix[100];
    char postfix[100];
    printf("���������ʽ��");
    scanf("%s", infix);
    convert(infix, postfix);
    double result = evaluate(postfix);
    printf("�������ǣ�%f", result);
    return 0;
}