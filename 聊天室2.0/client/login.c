#include "func.h"
extern INFO Add_INFO;
// extern pthread_cond_t cond;
// extern pthread_mutex_t mutex;
extern int ID;
void login(int sockfd)
{
    // INFO *Login_INFO = (INFO *)malloc(sizeof(INFO) * 1);
NEXT:
    Add_INFO.CMD = LOGIN;
    printf("请输入你的ID\n");
    scanf("%s", Add_INFO.id);
    printf("请输入你的密码\n");
    scanf("%s", Add_INFO.paswd);

    if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("send");
    }
   // printf("send successful\n");
    // pthread_cond_signal(&cond);
    // printf("signal send\n");
    // usleep(5);
    // pthread_cond_wait(&cond, &mutex);
    //pthread_cond_wait(&cond, &mutex);
    if (recv(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
    {
        ERRLOG("recv");
    }
    // if(Add_INFO.CMD == PRIVATE_CONFIRM)
    // {
    //     pthread_cond_signal(&cond);
    // }
   // printf("111111111111\n");
    if (Add_INFO.flag == SUCCESS)
    {
        printf("登录成功！\n");
    }
    if (Add_INFO.flag == FAILURE)
    {
        printf("账号密码有误！请重新登录\n");
        memset(&Add_INFO, 0, sizeof(INFO));
        goto NEXT;
    }
    memset(&Add_INFO, 0, sizeof(INFO));
    // free(Login_INFO);
}