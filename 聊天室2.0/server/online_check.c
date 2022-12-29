#include "func.h"
extern Online *Head;
void online_check(void *arg)
{
    printf("在线用户检查！\n");
    INFO Temp = *(INFO *)arg;
    Online *p = Head->next;
    while (p != NULL)
    {

        if (Temp.acceptfd != p->acceptfd)
        {
            strcat(Temp.txt, p->name);
            strcat(Temp.txt, "\t");
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    Temp.CMD = ONLINE_CHECK;
    send(Temp.acceptfd, &Temp, sizeof(INFO), 0);
    memset(&Temp,0,sizeof(INFO));
}