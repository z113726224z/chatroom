#include "func.h"
// pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
INFO Add_INFO;
int M = 0;
int G = 0;
int P = 0;
int main(int argc, char const *argv[])
{
    int sockfd;
    sockfd = client_init();
    char buf[N] = {0};
    int choice = 0;
    int ret = 0;
    // pthread_mutex_init(&mutex, NULL); //动态初始化一把锁
    // pthread_cond_init(&cond, NULL);   //初始化条件变量
    // pthread_t thread;
    // if (pthread_create(&thread, NULL, receive, &sockfd) != 0)
    // {
    //     ERRLOG("pthread_create");
    // }
    // if (pthread_detach(thread) != 0)
    // {
    //     ERRLOG("pthread_detach");
    // }
    while (1)
    {
        // printf("main CMD = %d\n", Add_INFO.CMD);
        // if (-1 == pthread_mutex_lock(&mutex))
        // {
        //     perror("lock");
        // }
        // if (Add_INFO.CMD == PRIVATE_CONFIRM)
        // {
        //     pthread_cond_signal(&cond);
        //     printf("send signal");
        //     // if (-1 == pthread_mutex_unlock(&mutex))
        //     // {
        //     //     perror("unlock");
        //     // }
        // }
        menu_1();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            signup(sockfd);
            break;
        case 2:
            login(sockfd);
            pthread_t thread;
            if (pthread_create(&thread, NULL, receive, &sockfd) != 0)
            {
                ERRLOG("pthread_create");
            }
            if (pthread_detach(thread) != 0)
            {
                ERRLOG("pthread_detach");
            }
            while (1)
            {
                menu_2();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    online_check(sockfd);
                    sleep(2);
                    break;
                case 2:
                    private
                    (sockfd);
                    break;
                case 3:
                    public
                    (sockfd);
                    break;
                case 4:
                    transport_send(sockfd);
                    break;
                case 5:
                    silence(sockfd);
                    break;
                case 6:
                    force_exit(sockfd);
                    break;
                case 7:
                    exit_client(sockfd);
                    exit(0);
                }
            }
        }
    }
    return 0;
}
