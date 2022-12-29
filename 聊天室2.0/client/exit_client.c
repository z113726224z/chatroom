#include "func.h"
extern INFO Add_INFO;

void exit_client(int sockfd)
{
    Add_INFO.CMD = EXIT;
    if(send(sockfd,&Add_INFO,sizeof(INFO),0) == -1)
    {
        ERRLOG("send");
    }
    sleep(1);
    return;
}