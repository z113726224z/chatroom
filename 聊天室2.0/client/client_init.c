#include "func.h"

int client_init()
{
    int sockfd;
    //第一步：创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        ERRLOG("socket error");
    }
    struct sockaddr_in serveraddr;
    //第二步：填充服务器网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(atoi("7777"));
    socklen_t addrlen = sizeof(serveraddr);
    //第三步：给服务器发送客户端的链接请求
    if (connect(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        ERRLOG("connect");
    }
    return sockfd;
}