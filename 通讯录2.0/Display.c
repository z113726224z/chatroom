#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <string.h>

void Display(Person_Linklist *Linklist_Head)
{
    // system("clear");
    Person_Linklist *p = Linklist_Head;
    if (p->next == Linklist_Head)
    {
        printf("当前通讯录为空，显示信息失败！\n");
        return;
    }
    else
    {
        SortbyName(Linklist_Head);
        Printall(Linklist_Head);
    }
    return;
}