#include "func.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern int Person_COUNT;

void DeleteybyID(Person_Linklist *Linklist_Head)
{
    Person_Linklist *p = Linklist_Head;
    Person_Linklist *q = Linklist_Head->next;
CONTINUE:
    if (p->next == Linklist_Head)
    {
        printf("当前通讯录为空！\n");
        sleep(1);
        return;
    }
    printf("请输入你要删除用户的ID！\n");
    char ch[20];
    scanf(" %s", ch);
    while (q != Linklist_Head)
    {
        if (strcmp(q->id, ch) == 0)
        {

            p->next = q->next;
            free(q);
            printf("删除成功\n");
            sleep(1);
            p = Linklist_Head;
            q = Linklist_Head->next;
            goto NEXT;
        }
        /* else
         {
             printf("未查询到该用户，请重新输入！\n");
             goto CONTINUE;
         }
         */
        p = p->next;
        q = q->next;
    }
    printf("未查询到该用户，请重新输入！\n");
    p = Linklist_Head;
    q = Linklist_Head->next;
    goto CONTINUE;
NEXT:
    printf("是否需要继续删除？ y/n \n");
    while (1)
    {
        char ans = '0';
        scanf("%c", &ans);
        if (ans == 'y')
        {
            goto CONTINUE;
        }
        if (ans == 'n')
        {
            return;
        }
    }
}
/*void DeleteybyID(Person_Linklist *Linklist_Head)
{
    Person_Linklist *p = Linklist_Head;
    if (p->next == Linklist_Head)
    {
        printf("当前通讯录为空！\n");
        return;
    }
    Person_Linklist *q = Linklist_Head;
    q = p->next;
    printf("请输入你要删除用户的ID！\n");
    char ch[20];
    scanf(" %s", ch);
    if (Person_COUNT == 1)
    {
        if (strcmp(q->id, ch) == 0)
        {
            p->next = q->next;
            p->next = p->next;
            q->next = q;
            free(q);
            q = NULL;
        }
    }
    if (Person_COUNT > 1)
    {
        while (q->next != Linklist_Head)
        {
            printf("11111111111111111\n");
            if (strcmp(q->id, ch) == 0)
            {
                printf("222222222222\n");
                p->next = p->next;
                q->next = q;
                free(q);
                q = NULL;
                printf("删除成功！是否需要继续删除？ y/n\n");
                while ('\n' != getchar())
                    ;
                char ans = '0';
                scanf("%c", &ans);
                if (ans == 'y')
                {
                    p = Linklist_Head;
                    if (p->next == Linklist_Head)
                    {
                        printf("当前通讯录为空，删除信息失败！\n");
                        return;
                    }
                    q = p->next;
                }
                else if (ans == 'n')
                {
                    printf("33333333333333\n");
                    return;
                }
            }
            p = p->next;
            q = q->next;
        }
    }
}*/