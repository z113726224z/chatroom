#include "func.h"

extern Online *Head;
void silence(void *arg)
{
    INFO TEMP = *(INFO *)arg;
    TEMP.CMD = SILENCE;
    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->acceptfd == TEMP.acceptfd)
        {
            if (strcmp(p->name, "admin") == 0)
            {
                TEMP.flag = SUCCESS;
            }
        }
    }
    if (TEMP.flag != SUCCESS)
    {
        TEMP.flag = FAILURE;
    }
    if (send(TEMP.acceptfd, &TEMP, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&TEMP, 0, sizeof(INFO));
}