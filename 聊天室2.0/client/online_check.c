#include "func.h"
extern INFO Add_INFO;
// extern pthread_mutex_t mutex;
// extern pthread_cond_t cond;
void online_check(int sockfd)
{
    // INFO *Private_INFO = (INFO *)malloc(sizeof(INFO) * 1);
    Add_INFO.CMD = ONLINE_CHECK;
    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    // printf("结构体发送成功！\n");
}