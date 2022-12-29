#include "func.h"

void *signup(void *arg)
{
    printf("signup work\n");
    INFO Add_INFO = *(INFO *)arg;
    // printf("acceptfd1 = %d\n", Add_INFO->accpecfd);
    int temp = Add_INFO.acceptfd;
    // ssize_t bytes;
    // if (bytes = recv(Add_INFO->accpecfd, Add_INFO, sizeof(INFO), 0) == -1)
    // {
    //     ERRLOG("recv");
    // }
    // printf("acceptfd2 = %d\n", Add_INFO->accpecfd);
    // Add_INFO->accpecfd = temp;
    // if (Add_INFO->CMD = SIGNUP)
    // {
    char buf[12];

    if (check_id(&Add_INFO) == 0)
    {
        printf("enter success\n");
        sqlite3 *ppdb;
        int ret = sqlite3_open("./INFO.db", &ppdb);
        if (ret != SQLITE_OK)
        {
            printf("sqlite3_open: %s\n", sqlite3_errmsg(ppdb));
        }

        //创建表
        char sql[128] = {0};
        sprintf(sql, "create table if not exists stu(id char,name char,paswd char);");
        ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
        if (ret != SQLITE_OK)
        {
            printf("sqlite3_open: %s\n", sqlite3_errmsg(ppdb));
        }
        memset(sql, 0, sizeof(sql));
        sprintf(sql, "insert into stu values('%s','%s','%s');", Add_INFO.id, Add_INFO.name, Add_INFO.paswd);
        ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
        Add_INFO.flag = SUCCESS;
        if (send(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0) == -1)
        {
            ERRLOG("signup success send");
        }
        printf("signup success\n");
        memset(&Add_INFO, 0, sizeof(INFO));
        
    }
    else
    {
        printf("enter failure\n");
        Add_INFO.flag = FAILURE;
        Add_INFO.acceptfd = temp;
        printf("acceptfd = %d\n", Add_INFO.acceptfd);
        if (send(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0) == -1)
        {
            ERRLOG("signup failure send");
        }
        printf("signup failure");
        memset(&Add_INFO, 0, sizeof(INFO));
        
    }

    // }
}