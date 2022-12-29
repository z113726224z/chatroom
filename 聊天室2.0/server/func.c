#include "func.h"
extern Online *Head;

void *func(void *arg)
{
    printf("pthread work\n");
    INFO Add_INFO = *(INFO *)arg;
    int temp = Add_INFO.acceptfd;

    ssize_t bytes;
    while (1)
    {
        if ((bytes = recv(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0)) == -1)
        {
            ERRLOG("func recv");
        }
        printf("线程收到结构体\n");
        printf("acceptfd = %d,id = %s,CMD = %d\n", Add_INFO.acceptfd, Add_INFO.id, Add_INFO.CMD);

        Add_INFO.acceptfd = temp;
        if (Add_INFO.CMD == SIGNUP) //注册
        {
            signup(&Add_INFO);
        }
        else if (Add_INFO.CMD == LOGIN) //登录
        {
            login(&Add_INFO);
        }
        else if (Add_INFO.CMD == ONLINE_CHECK) //在线检查
        {
            online_check(&Add_INFO);
        }
        else if (Add_INFO.CMD == PRIVATE) //私聊
        {
            private(&Add_INFO);
        }
        else if (Add_INFO.CMD == PUBLIC)
        {
            public(&Add_INFO);
        }
        else if (Add_INFO.CMD == TRANSPORT)
        {
            transport(&Add_INFO);
        }
        else if (Add_INFO.CMD == EXIT)
        {
            exit_client(&Add_INFO);
            pthread_exit(NULL);
        }
        else if (Add_INFO.CMD == SILENCE)
        {
            // printf("进入禁言\n");
            // printf("flag = %d\n",Add_INFO.flag);
            silence(&Add_INFO);
            if (Add_INFO.flag == SUCCESS)
            {
                silence_2(&Add_INFO);
            }
        }
        else if (Add_INFO.CMD == FROCE_EXIT)
        {
            printf("进入踢人\n");
            printf("flag = %d\n", Add_INFO.flag);
            force_exit(&Add_INFO);
            printf("222222222\n");
            printf("flag = %d\n", Add_INFO.flag);
            if (Add_INFO.flag == SUCCESS)
            {
                printf("3333333\n");
                force_exit2(&Add_INFO);
            }
        }
    }
}