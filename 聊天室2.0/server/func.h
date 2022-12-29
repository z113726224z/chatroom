#ifndef _SERVER_H_
#define _SERVER_H_
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
#include <sqlite3.h>

#define N 128
#define Q 666
#define SUCCESS 777
#define FAILURE 778
#define MAXSIZE 1024

#define SIGNUP 779
#define LOGIN 780
#define PRIVATE 781
#define PRIVATE_CONFIRM 784
#define PUBLIC 782
#define ONLINE_CHECK 783
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
}INFO;

typedef struct person
{
    int acceptfd;
    char name[12];
    struct person *next;
}Online;


struct job  //任务节点  （队列的节点）
{
	void*(*func)(void *arg);  //函数指针，用于存放任务
	void *arg;               //用来给任务函数传参使用
	struct job *next;      //队列节点的指针域
};
struct pthreadpool
{
	int m_threadNum;  //已开启的线程的数量
	pthread_t *m_pthreadIds; //保存线程池中线程的ID

	struct job *head;  //任务队列的头
	struct job *tail;  //任务队列的尾
	int m_QueueMaNum;  //任务队列的最大数
	int m_QueueCurNum;  //任务队列已经有了多少个任务

	pthread_mutex_t mutex;

	pthread_cond_t m_queueEmpty;   //任务队列为空的条件
	pthread_cond_t m_queueNotEmpty; //任务队列不为空的条件
	pthread_cond_t m_queueNotFull;  //任务队列不为满的条件
	int pool_close;
};

int check_id(INFO* Add_INFO);
void *signup(void *arg);
void *login(void* arg);
Online* Online_LinklistCreate();
void online_check(void *arg);
void leng(Online *Head);
void *threadpool_Run(void *arg);
struct pthreadpool *ThreadPool_init(int threadNum, int queueMaxNum);
void thread_add_job(struct pthreadpool *pool, void *(*func)(void *), void *arg);
void thread_destroy(struct pthreadpool *pool);
void *func(void *arg);
void private(void *arg);
void public(void *arg);
void transport(void *arg);
void silence(void *arg);
void silence_2(void *arg);
void exit_client(void *arg);
void force_exit(void *arg);
void force_exit2(void *arg);
#endif