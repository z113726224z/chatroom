#include "func.h"
extern INFO Add_INFO;

void signup(int sockfd)
{
    // INFO *Add_INFO = (INFO *)malloc(sizeof(INFO) * 1);
NEXT:
    printf("请输入你的ID\n");
    scanf("%s", Add_INFO.id);
    printf("请输入你的昵称\n");
    scanf("%s", Add_INFO.name);
    printf("请输入你的密码\n");
    scanf("%s", Add_INFO.paswd);
    Add_INFO.CMD = SIGNUP;

    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
    
    if (recv(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("recv");
    }
    
    if (Add_INFO.flag == SUCCESS)
    {
        printf("注册用户成功!\n");
    }
    else if (Add_INFO.flag == FAILURE)
    {
        printf("ID已存在，请重新注册！\n");
        memset(&Add_INFO,0,sizeof(INFO));
        goto NEXT;
    }
    memset(&Add_INFO,0,sizeof(INFO));
}