#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <sys/epoll.h>
#include <string.h>

#define Q 666
#define N 128
#define SUCCESS 777
#define FAILURE 778

#define SIGNUP 779
#define LOGIN 780
#define PRIVATE 781
#define PUBLIC 782
#define ONLINE_CHECK 783
#define PRIVATE_CONFIRM 784
#define TRANSPORT 785
#define EXIT 786
#define SILENCE 787
#define FROCE_EXIT 788


#define ERRLOG(errmsg)                                          \
    do                                                          \
    {                                                           \
        perror(errmsg);                                         \
        printf("%s - %s - %d\n", __FILE__, __func__, __LINE__); \
        exit(1);                                                \
    } while (0)
typedef struct info
{
    char id[12];
    char name[12];
    char paswd[12];
    int flag;
    char txt[N];
    char filename[12];
    int ret;
    int acceptfd;
    int CMD;

} INFO;

pthread_cond_t cond;
pthread_mutex_t mutex;

int client_init();
void menu_1();
void signup(int sockfd);
void login(int sockfd);
void menu_2();
void online_check(int sockfd);
void private(int sockfd);
void *receive(void *arg);
void send_msg(int sockfd);
void public(int sockfd);
void transport_send(int sockfd);
void transport_receive(void *arg);
void exit_client(int sockfd);
void silence(int sockfd);
void force_exit(int sockfd);
#endif