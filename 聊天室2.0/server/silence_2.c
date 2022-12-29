#include "func.h"
extern Online *Head;
void silence_2(void *arg)
{
    INFO TEMP = *(INFO *)arg;
    // printf("name = %s\n",TEMP.name);
    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->name, TEMP.name) == 0)
        {
            TEMP.acceptfd = p->acceptfd;
        }
    }

    TEMP.CMD = SILENCE;
    TEMP.ret = SUCCESS;
    // TEMP.flag = SUCCESS;
    if (send(TEMP.acceptfd, &TEMP, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&TEMP, 0, sizeof(INFO));
}