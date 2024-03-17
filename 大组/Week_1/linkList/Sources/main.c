#include "user.h"
#include <stdio.h>

int main()
{
    Linklist* list = create();
    User user;
    int choice;
    do {
        printf("\n用户管理系统\n");
        printf("1. 添加用户\n");
        printf("2. 显示用户列表\n");
        printf("3. 退出\n");
        printf("请选择操作：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入用户名：");
            scanf_s("%s", user.name);
        out:
            printf("请输入电话号码：");
            scanf_s("%s", user.num);
            if (strlen(user.num) != 11) {
                printf("无效选择，请重新输入。\n");
                while (getchar() != '\n');  // 清空输入缓冲区
                goto out;
            }
            else {
                add(list, user);
                printf("用户添加成功！\n");
            }
            break;
        case 2:
            print(list);
            break;
        case 3:
            printf("谢谢使用，再见！\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    } while (choice != 3);
    freelist(list);  // 程序结束时释放链表所占用的内存
    return 0;
}