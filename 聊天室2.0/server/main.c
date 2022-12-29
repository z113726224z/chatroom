#include "func.h"
Online *Head;


int main(int argc, char const *argv[])
{
    int sockfd, acceptfd;
    ssize_t bytes;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        ERRLOG("socket error");
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(atoi("7777"));

    if (bind(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        ERRLOG("bind error");
    }

    if (listen(sockfd, 5) == -1)
    {
        ERRLOG("listen error");
    }
    //    int opt = 1;
    //   setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); //设置地址可以被重复绑定

    //创建epoll对象
    int epollfd = epoll_create(MAXSIZE);
    if (-1 == epollfd)
    {
        perror("epoll_create");
        exit(1);
    }
    printf("pollfd = %d\n", epollfd);
    struct epoll_event ev, events[MAXSIZE] = {0};
    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    int ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev); //注册事件：sockfd
    if (-1 == ret)
    {
        perror("epoll_ctl");
        exit(1);
    }
    Head = Online_LinklistCreate();
    INFO *Temp_INFO = (INFO *)malloc(sizeof(INFO) * 1);
   
    // struct pthreadpool *pool = ThreadPool_init(10, 20);
    while (1)
    {
        printf("epoll—wait等待事件到来！\n");
        int num = epoll_wait(epollfd, events, MAXSIZE, -1); //等待事件的发生， -1:表示阻塞等待
        if (-1 == num)
        {
            perror("epoll_wait");
            exit(1);
        }
        printf("开始处理事件！\n");
        char buf[N] = {0};
        for (int i = 0; i < num; i++)
        {
            if (events[i].data.fd == sockfd) //有客户端发起连接
            {
                //第五步：阻塞等待客户端的连接
                if ((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
                {
                    ERRLOG("accept error");
                }
                ev.events = EPOLLIN;
                ev.data.fd = acceptfd;

                // ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, acceptfd, &ev); //注册事件：sockfd
                // if (-1 == ret)
                // {
                //     perror("epoll_ctl");
                //     exit(1);
                // }
                //打印客户端的信息
                printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
                pthread_t thread;
                Temp_INFO->acceptfd = acceptfd;
                if (pthread_create(&thread, NULL, func, Temp_INFO) != 0)
                {
                    ERRLOG("pthread_create");
                }
                printf("detach work!\n");
                if (pthread_detach(thread) != 0)
                {
                    ERRLOG("pthread_create");
                }
            }
            // else //有客户端发消息
            // {
            //     if (events[i].events & EPOLLIN) //如果事件是可读的
            //     {
            //         printf("accpectfd = %d\n", events[i].data.fd);
            //         Temp_INFO->acceptfd = events->data.fd;
            //         // ret = epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
            //         // if (-1 == ret)
            //         // {
            //         //     perror("epoll_ctl");
            //         //     exit(1);
            //         // }
            //         printf("accpectfd = %d\n", events[i].data.fd);
            //         pthread_t thread;
            //         if (pthread_create(&thread, NULL, func, Temp_INFO) != 0)
            //         {
            //             ERRLOG("pthread_create");
            //         }
            //         if (pthread_detach(thread) != 0)
            //         {
            //             ERRLOG("pthread_create");
            //         }
            //         //         Temp_INFO->accpecfd = events[i].data.fd;
            //         //         printf("main acceptfd = %d\n",Temp_INFO->accpecfd);
            //         //         thread_add_job(pool,func,Temp_INFO);
            //         //         // bytes = recv(events[i].data.fd, Temp_INFO, sizeof(INFO), 0);
            //         //         // if (Temp_INFO->CMD == SIGNUP) //注册
            //         //         // {
            //         //         //     signup(Temp_INFO);
            //         //         //     send(events[i].data.fd, Temp_INFO, sizeof(INFO), 0);
            //         //         //     memset(Temp_INFO, 0, sizeof(INFO));
            //         //         // }
            //         //         // else if (Temp_INFO->CMD == LOGIN) //登录
            //         //         // {
            //         //         //     login(Temp_INFO, events[i].data.fd);
            //         //         //     send(events[i].data.fd, Temp_INFO, sizeof(INFO), 0);
            //         //         //     memset(Temp_INFO, 0, sizeof(INFO));
            //         //         //     printf("22222222222222\n");
            //         //         // }
            //         //         // else if (Temp_INFO->CMD == ONLINE_CHECK) //私聊
            //         //         // {
            //         //         //     printf("111111111\n");
            //         //         //     online_check(Temp_INFO, events[i].data.fd);
            //         //         //     printf("222222222222222\n");
            //         //         //     send(events[i].data.fd, Temp_INFO, sizeof(INFO), 0);
            //         //         //     memset(Temp_INFO, 0, sizeof(INFO));
            //         //         // }
            //         //         // else if (Temp_INFO->CMD == PRIVATE)
            //         //         // {
            //         //         // }
            //     }
            // }
        }
    }
    close(epollfd);
    return 0;
}
