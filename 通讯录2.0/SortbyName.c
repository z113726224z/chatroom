#include "func.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern int Person_COUNT;

void SortbyName(Person_Linklist *Linklist_Head)
{
    if (Linklist_Head->next == Linklist_Head)
    {
        printf("排序失败，当前列表为空！\n");
        sleep(1);
        return;
    }
    else if (Linklist_Head->next->next == Linklist_Head)
    {
        return;
    }
    Person_Linklist *p = Linklist_Head;
    Person_Linklist *q = p->next;
    Person_Linklist *l = q->next;
    int i = 0;
    for (i = 0; i < Person_COUNT - 1; i++)
    {
 
        while (q->next != Linklist_Head)
        {
            if (strcmp(q->name, l->name) > 0)
            {
                Person_Linklist *tmp = q;
                q->next = l->next;
                p->next = l;
                l->next = q;

                q = l;
                l = tmp;

            }
            p = p->next;
            q = q->next;
            l = l->next;

        }
        p = Linklist_Head;
        q = p->next;
        l = q->next;
    }
    return;
}