#include "func.h"
extern INFO Add_INFO;
extern int P;
void public(int sockfd)
{
    if (P == 0)
    {
        printf("请输入群聊内容\n");
        while (1)
        {
            scanf("%s", Add_INFO.txt);
            Add_INFO.CMD = PUBLIC;

            if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
            {
                ERRLOG("send");
            }
            if (strcmp(Add_INFO.txt, "quit") == 0)
            {
                return;
            }
            memset(&Add_INFO.txt, 0, N);
        }
    }
    else if(P == 1)
    {
        printf("您被禁言了！\n");
        sleep(1);
    }
}