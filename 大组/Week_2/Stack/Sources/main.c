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
    printf("请输入计算式：");
    scanf("%s", infix);
    convert(infix, postfix);
    double result = evaluate(postfix);
    printf("运算结果是：%f", result);
    return 0;
}