#include "func.h"
extern INFO Add_INFO;
extern int G;
void force_exit(int sockfd)
{
    memset(&Add_INFO,0,sizeof(INFO));
    Add_INFO.CMD = FROCE_EXIT;
    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&Add_INFO,0,sizeof(INFO));
    sleep(1);
    if (G == 1)
    {
        G = 0;
        printf("您不是admin用户\n");
        sleep(1);
        return;
    }
    printf("请输入您要踢出的用户\n");
    scanf("%s", Add_INFO.name);

    Add_INFO.CMD = FROCE_EXIT;
    Add_INFO.flag = SUCCESS;
    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&Add_INFO,0,sizeof(INFO));
}