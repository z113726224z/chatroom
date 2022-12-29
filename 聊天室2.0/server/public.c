#include "func.h"
extern Online *Head;

void public(void *arg)
{
    INFO temp = *(INFO *)arg;
    INFO Public;
    Public.acceptfd = temp.acceptfd;
    Public.CMD = PUBLIC;
    strcpy(Public.txt, temp.txt);
    memset(&temp, 0, sizeof(INFO));

    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->acceptfd == Public.acceptfd)
        {
            strcpy(Public.name, p->name);
        }
    }
    p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->acceptfd != Public.acceptfd)
        {
            if (send(p->acceptfd, &Public, sizeof(INFO), 0) == -1) //发送给发送用户SUCCESS
            {
                ERRLOG("send");
            }
            printf("p->acceptfd = %d\n",p->acceptfd);
        }
    }
}