#include <stdio.h>
#include "func.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void Modify(Person_Linklist *Linklist_Head)
{
    Person_Linklist *p = Linklist_Head;
    if (p->next == Linklist_Head)
    {
        printf("当前通讯录为空！\n");
        sleep(1);
        return;
    }
    p = p->next;
REMODIFY:
    printf("请输入你要修改用户的ID\n");
    char ch[20] = "0";
CONTINUE:
    scanf(" %s", ch);
    while (p != Linklist_Head)
    {

        if (strcmp(ch, p->id) == 0)
        {
            printfp(p);
            printf("请输入你要修改的内容\n");
            int num = 0;
            scanf("%d", &num);
            switch (num)
            {
            case 1:
                printf("请输入新的ID\n");
                char tmp1[20] = "0";
            REINPUT:
                scanf(" %s", tmp1);
                Person_Linklist *q = Linklist_Head->next;
                while (q != Linklist_Head)
                {
                    if (strcmp(tmp1, q->id) == 0 && tmp1 != q->id)
                    {
                        printf("ID已存在，请重新输入！\n");
                        goto REINPUT;
                    }
                    q = q->next;
                }
                strcpy(p->id, tmp1);
                printf("修改成功！\n");
                sleep(1);
                printfp(p);
                printf("是否需要继续修改 y/n\n");
                char ans1 = '0';
                scanf(" %c",&ans1);
                if (ans1 == 'y')
                {
                    p = Linklist_Head->next;
                    goto REMODIFY;
                }
                if (ans1 == 'n')
                {
                    return;
                }
            case 2:
                printf("请输入新的名字\n");
                char tmp2[20] = "0";
                scanf(" %s", tmp2);
                strcpy(p->name, tmp2);
                printf("修改成功！\n");
                sleep(1);
                printfp(p);
                printf("是否需要继续修改 y/n\n");
                char ans2 = '0';
                scanf(" %c",&ans2);
                if (ans2 == 'y')
                {
                    p = Linklist_Head->next;
                    goto REMODIFY;
                }
                if (ans2 == 'n')
                {
                    return;
                }
            case 3:
                printf("请输入新的年龄\n");
                char tmp3[20] = "0";
                scanf(" %s", tmp3);
                strcpy(p->age, tmp3);
                printf("修改成功！\n");
                sleep(1);
                printfp(p);
                printf("是否需要继续修改 y/n\n");
                char ans3 = '0';
                scanf(" %c",&ans3);
                if (ans3 == 'y')
                {
                    p = Linklist_Head->next;
                    goto REMODIFY;
                }
                if (ans3 == 'n')
                {
                    return;
                }
            case 4:
                printf("请输入新的性别\n");
                char tmp4[20] = "0";
                scanf(" %s", tmp4);
                strcpy(p->sex, tmp4);
                printf("修改成功\n");
                sleep(1);
                printfp(p);
                printf("是否需要继续修改 y/n\n");
                char ans4 = '0';
                scanf(" %c",&ans4);
                if (ans4 == 'y')
                {
                    p = Linklist_Head->next;
                    goto REMODIFY;
                }
                if (ans4 == 'n')
                {
                    return;
                }
            case 5:
                printf("请输入新的电话\n");
                char tmp5[20] = "0";
            REINPUT2:
                scanf(" %s", tmp5);
                if (strlen(tmp5) != 11)
                {
                    printf("电话有误，请重新输入！\n");
                    goto REINPUT2;
                }
                strcpy(p->tel, tmp5);
                printf("修改成功！\n");
                sleep(1);
                printfp(p);
                printf("是否需要继续修改 y/n\n");
                char ans5 = '0';
                scanf(" %c",&ans5);
                if (ans5 == 'y')
                {
                    p = Linklist_Head->next;
                    goto REMODIFY;
                }
                if (ans5 == 'n')
                {
                    return;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
    printf("未查询到该用户，请重新输入！\n");
    goto CONTINUE;
}