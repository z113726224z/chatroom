#include "func.h"
extern Online *Head;

void transport(void *arg)
{
    printf("transport work!\n");
    INFO Temp = *(INFO *)arg;
    INFO TEMP;

    TEMP.CMD = TRANSPORT;
    TEMP.acceptfd = Temp.acceptfd;
    TEMP.flag = Temp.flag;
    strcpy(TEMP.filename, Temp.filename);
    strcpy(TEMP.txt, Temp.txt);
    strcpy(TEMP.name,Temp.name);
    printf("TEMP.name = %s\n",TEMP.name);
    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->name, TEMP.name) == 0)
        {
            TEMP.acceptfd = p->acceptfd;
        }
    }
    printf("TEMP = %d\n",TEMP.acceptfd);
    if (send(TEMP.acceptfd, &TEMP, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    printf("%s\n",TEMP.txt);
    memset(&TEMP, 0, sizeof(INFO));

}