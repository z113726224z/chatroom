#include "func.h"
extern INFO Add_INFO;
extern int G;
void silence(int sockfd)
{
    Add_INFO.CMD = SILENCE;
    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&Add_INFO,0,sizeof(INFO));
    usleep(500);
    if( G == 1)
    {
        G = 0;
        printf("您不是admin用户\n");
        sleep(1);
        return;
    }
    printf("请输入你要禁言的用户\n");
    scanf("%s",Add_INFO.name);
    
    Add_INFO.CMD = SILENCE;
    Add_INFO.flag = SUCCESS;
    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    memset(&Add_INFO,0,sizeof(INFO));
}
