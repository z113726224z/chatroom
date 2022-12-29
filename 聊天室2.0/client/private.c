#include "func.h"
extern INFO Add_INFO;
extern int M;
extern int P;
// extern pthread_mutex_t mutex;
// extern pthread_cond_t cond;
void private(int sockfd)
{
    //printf("P = %d\n",P);
    // INFO *Private_INFO = (INFO *)malloc(sizeof(INFO) * 1);
    if (P == 0)
    {
        printf("请输入你要私聊的用户：\n");
        Add_INFO.CMD = PRIVATE;
        Add_INFO.ret = 0;
        scanf("%s", Add_INFO.name);

        if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
        {
            ERRLOG("send");
        }
        usleep(500);
        if (M == 1)
        {
            M = 0;
            sleep(1);
            return;
        }
        system("clear");
        while (1)
        {
            scanf("%s", Add_INFO.txt);
            Add_INFO.CMD = PRIVATE;
            Add_INFO.ret = SUCCESS;

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
        printf("您被禁言了!\n");
        sleep(1);
    }
}