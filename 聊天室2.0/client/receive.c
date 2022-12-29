#include "func.h"
// extern pthread_mutex_t mutex;
// extern pthread_cond_t cond;
extern INFO Add_INFO;
extern int M;
extern int G;
extern int P;
void *receive(void *arg)
{
    // INFO *Add_INFO = (INFO *)malloc(sizeof(INFO) * 1);
    int sockfd = *(int *)arg;
    // printf("子线程工作\n");
    while (1)
    {
        if (recv(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
        {
            ERRLOG("recv");
        }
        // printf("receive work\n");
        if (Add_INFO.CMD == ONLINE_CHECK)
        {
            if (strcmp(Add_INFO.txt, "") == 0)
            {
                printf("当前无在线用户\n");
            }
            else
            {
                printf("当前在线的用户为：%s\n", Add_INFO.txt);
            }
        }
        if (Add_INFO.CMD == PRIVATE) //收到私聊请求
        {
            if (Add_INFO.flag == FAILURE)
            {
                printf("用户不在线或不存在！\n");
                memset(&Add_INFO, 0, sizeof(INFO));
                M = 1;
                sleep(1);
            }
            else if (Add_INFO.flag == SUCCESS)
            {
                // printf("进入私聊界面！\n");
                // system("clear");
            }
        }
        if (Add_INFO.CMD == PRIVATE_CONFIRM)
        {
            if (strcmp(Add_INFO.txt, "quit") == 0)
            {
                printf("%s退出了私聊\n", Add_INFO.name);
            }
            if (strcmp(Add_INFO.txt, "quit") != 0)
            {
                printf("%s发来了消息：%s\n", Add_INFO.name, Add_INFO.txt);
            }
        }
        if (Add_INFO.CMD == PUBLIC)
        {
            if (strcmp(Add_INFO.txt, "quit") != 0)
            {
                printf("%s群发了消息：%s\n", Add_INFO.name, Add_INFO.txt);
            }
        }
        if (Add_INFO.CMD == TRANSPORT)
        {
            transport_receive(&Add_INFO);
            memset(&Add_INFO, 0, sizeof(INFO));
        }
        if (Add_INFO.CMD == SILENCE)
        {
            // printf("收到标志位了\n");
            // printf("flag = %d\n",Add_INFO.flag);
            if (Add_INFO.flag == FAILURE)
            {
                memset(&Add_INFO, 0, sizeof(INFO));
                G = 1;
                sleep(1);
            }
            // printf("ret = %d\n",Add_INFO.ret);
            if (Add_INFO.ret == SUCCESS)
            {
                P = 1;
                memset(&Add_INFO,0,sizeof(INFO));
            }
        }
        if (Add_INFO.CMD == FROCE_EXIT)
        {
           // printf("ret = %d\n",Add_INFO.ret);
            if (Add_INFO.flag == FAILURE)
            {
                memset(&Add_INFO, 0, sizeof(INFO));
                G = 1;
                sleep(1);
            }
            if (Add_INFO.ret == SUCCESS)
            {
                printf("您被管理员踢出了聊天室！\n");
                sleep(1);
                exit_client(sockfd);
                exit(0);
            }
        }
    }
}