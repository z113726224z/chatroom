#include <stdio.h>
#include "func.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void Search(Person_Linklist *Linklist_Head)
{
    Person_Linklist *p = Linklist_Head;
    if (p->next == Linklist_Head)
    {
        printf("当前通讯录为空！\n");
        sleep(1);
        return;
    }
    p = p->next;
    printf("请输入你要查找用户的ID或姓名\n");
    char ch[20] = "0";
CONTINUE:
    scanf(" %s", ch);
    while (p != Linklist_Head)
    {

        if (strcmp(ch, p->id) == 0 || strcmp(ch,p->name) == 0)
        {
            system("clear");
            printf("******************************************************\n");
            printf("ID号：%s\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("年龄：%s\n", p->age);
            printf("性别：%s\n", p->sex);
            printf("电话：%s\n", p->tel);
            printf("******************************************************\n");
            printf("请按q键退出！\n");
            while (1)
            {
                char re = '0';
                scanf("%c", &re);
                if (re == 'q')
                {
                    return;
                }
            }
        }
        p = p->next;
    }
    printf("未查询到该用户，请重新输入！\n");
    goto CONTINUE;
}