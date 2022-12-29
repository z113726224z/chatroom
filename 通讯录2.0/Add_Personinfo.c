#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <string.h>


extern int Person_COUNT;

void Add_Personinfo(Person_Linklist *Linklist_Head)
{
CONTINUE:
    if (Linklist_Head->next == Linklist_Head)
    {
        // printf("kong\n");
        Person_Linklist *P_INFO = (Person_Linklist *)malloc(sizeof(Person_Linklist) * 1);
        P_INFO->next = NULL;

        P_INFO->next = Linklist_Head->next;
        Linklist_Head->next = P_INFO;
        printf("请输入ID号：\n");
        scanf(" %s", P_INFO->id);
        printf("请输入姓名：\n");
        scanf(" %s", P_INFO->name);
        printf("请输入年龄：\n");
        scanf(" %s", P_INFO->age);
        printf("请输入性别：\n");
        scanf(" %s", P_INFO->sex);
        printf("请输入电话：\n");
    REINPUT1:
        scanf(" %s", P_INFO->tel);
        if (strlen(P_INFO->tel) != 11)
        {
            printf("电话有误，请重新输入！\n");
            goto REINPUT1;
        }
        Person_COUNT++;
        Printpresent(Linklist_Head);
        printf("是否要继续添加新用户? y/n\n");
        while ('\n' != getchar())
            ;
        char ans = '0';
        scanf(" %c", &ans);
        if (ans == 'y')
        {
            goto CONTINUE;
        }
        else if (ans == 'n')
        {
            return;
        }
    }
    else
    {
        //    printf("211111111111\n");
        Person_Linklist *P_INFO = (Person_Linklist *)malloc(sizeof(Person_Linklist) * 1);
        P_INFO->next = NULL;
        printf("请输入ID号：\n");
    REINPUT:
        scanf(" %s", P_INFO->id);
        Person_Linklist *q = Linklist_Head->next;
        while (q != Linklist_Head)
        {
            if (strcmp(P_INFO->id, q->id) == 0)
            {
                printf("ID已存在，请重新输入！\n");
                goto REINPUT;
            }
            q = q->next;
        }
        printf("请输入姓名：\n");
        scanf(" %s", P_INFO->name);
        printf("请输入年龄：\n");
        scanf(" %s", P_INFO->age);
        printf("请输入性别：\n");
        scanf(" %s", P_INFO->sex);
        printf("请输入电话：\n");
    REINPUT2:
        scanf(" %s", P_INFO->tel);
        if (strlen(P_INFO->tel) != 11)
        {
            printf("电话有误，请重新输入！\n");
            goto REINPUT2;
        }
        P_INFO->next = Linklist_Head->next;
        Linklist_Head->next = P_INFO;
        Person_COUNT++;
        Printpresent(Linklist_Head);
        printf("是否要继续添加新用户? y/n\n");
        while ('\n' != getchar())
            ;
        char ans = '0';
        scanf(" %c", &ans);
        if (ans == 'y')
        {
            goto CONTINUE;
        }
        else if (ans == 'n')
        {
            return;
        }
    }
}