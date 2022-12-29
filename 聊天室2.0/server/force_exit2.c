#include "func.h"
extern Online *Head;
void force_exit2(void *arg)
{
    INFO TEMP = *(INFO *)arg;
    //  printf("name = %s\n",TEMP.name);
    printf("11acceptfd = %d\n", TEMP.acceptfd);
    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->name, TEMP.name) == 0)
        {
            TEMP.acceptfd = p->acceptfd;
        }
    }

    TEMP.CMD = FROCE_EXIT;
    TEMP.ret = SUCCESS;
    // TEMP.flag = SUCCESS;
    printf("22acceptfd = %d\n", TEMP.acceptfd);
    if (send(TEMP.acceptfd, &TEMP, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&TEMP,0,sizeof(INFO));
}