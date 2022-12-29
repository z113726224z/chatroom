#include "func.h"
extern Online *Head;

void private(void *arg)
{
    INFO Temp = *(INFO *)arg;
    INFO TEMP;
    int send_acceptfd = Temp.acceptfd; //发送消息用户的acceptfd
    int recv_acceptfd = 0;             //接收消息用户的acceptfd
    char recv_name[12] = {0};
    char send_name[12] = {0};
    strcpy(recv_name, Temp.name);

    strcpy(TEMP.name, Temp.name);
    TEMP.acceptfd = Temp.acceptfd;
    strcpy(TEMP.txt, Temp.txt);
    TEMP.ret = Temp.ret;
    memset(&Temp, 0, sizeof(INFO));
    //找到发送人的名字
    Online *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->acceptfd == TEMP.acceptfd)
        {
            strcpy(send_name, p->name);
        }
    }
    //找到接收人的acceptfd
    p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->name, TEMP.name) == 0)
        {
            recv_acceptfd = p->acceptfd;
        }
    }

    if (recv_acceptfd == 0) //用户不在线
    {
        TEMP.CMD = PRIVATE;
        TEMP.flag = FAILURE;
        if (send(send_acceptfd, &TEMP, sizeof(INFO), 0) == -1)
        {
            ERRLOG("send");
        }
    }
    else if (recv_acceptfd != 0)
    {
        TEMP.CMD = PRIVATE;
        TEMP.flag = SUCCESS;
        if (send(send_acceptfd, &TEMP, sizeof(INFO), 0) == -1) //发送给发送用户SUCCESS
        {
            ERRLOG("send");
        }
        if (TEMP.ret == SUCCESS)
        {
            TEMP.CMD = PRIVATE_CONFIRM;
            strcpy(TEMP.name, send_name);
            if (send(recv_acceptfd, &TEMP, sizeof(INFO), 0) == -1)
            {
                ERRLOG("send");
            }
            memset(&TEMP, 0, sizeof(INFO));
        }
        
    }
}