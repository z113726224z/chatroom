#include "func.h"

extern Online *Head;
void exit_client(void *arg)
{
    INFO TEMP = *(INFO *)arg;
    Online *p = Head;
    Online *q = Head->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = Head;
    p = Head;
    while (q != Head)
    {
        if (q->acceptfd == TEMP.acceptfd)
        {
            p->next = q->next;
            q->next = q;
            free(q);
            p = Head->next;
            break;
        }
        p = p->next;
        q = q->next;
    }
    while(p->next != Head)
    {
        p = p->next;
    }
    p->next = NULL;
}