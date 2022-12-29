#include "func.h"
extern Online *Head;
void *login(void *arg)
{
    INFO Add_INFO = *(INFO *)arg;
    // printf("acceptfd1 = %d\n", Add_INFO->accpecfd);
    int temp = Add_INFO.acceptfd;
    ssize_t bytes;
    // if (bytes = recv(Add_INFO->accpecfd, Add_INFO, sizeof(INFO), 0) == -1)
    // {
    //     ERRLOG("recv");
    // }
    // Add_INFO->accpecfd = temp;
    sqlite3 *ppdb;
    char **result;
    int row, column;                            //数据库句柄指针，用来表示操作某一个数据库
    int ret = sqlite3_open("./INFO.db", &ppdb); //打开或者创建一个数据库
    while (1)
    {
        if (ret != SQLITE_OK)
        {
            printf("sqlite3_open: %s\n", sqlite3_errmsg(ppdb));
        }
        char sql[128] = {0};
        sprintf(sql, "select *from stu where id = '%s';", Add_INFO.id);
       
        ret = sqlite3_get_table(ppdb, sql, &result, &row, &column, NULL);
        printf("%s %s %s\n", result[3], result[4], result[5]);
        if (ret != SQLITE_OK)
        {
            printf("sqlite3_get_table: %s\n", sqlite3_errmsg(ppdb));
        }
        
        if (row == 1)
        {
            if (strcmp(Add_INFO.paswd, result[5]) == 0)
            {
                Add_INFO.flag = SUCCESS;
                Online *Node = (Online *)malloc(sizeof(Online) * 1);
                Node->acceptfd = Add_INFO.acceptfd;
                strcpy(Node->name, result[4]);
                Node->next = Head->next;
                Head->next = Node;
                Add_INFO.acceptfd = temp;
                sleep(1);
                if (send(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0) == -1)
                {
                    ERRLOG("login send1");
                }
                printf("login 111111111\n");
                printf("success send successful\n");
                break;
            }
            // Add_INFO->accpecfd = temp;
            // if (send(Add_INFO->accpecfd, Add_INFO, sizeof(INFO), 0) == -1)
            // {
            //     ERRLOG("login send");
            // }
            memset(&Add_INFO, 0, sizeof(INFO));
            if (strcmp(Add_INFO.paswd, result[5]) != 0)
            {
                Add_INFO.flag = FAILURE;
                Add_INFO.acceptfd = temp;
                if (send(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0) == -1)
                {
                    ERRLOG("login send2");
                }
                printf("failure send successful\n");
                memset(&Add_INFO, 0, sizeof(INFO));
                break;
            }
        }
        else if (row != 1)
        {
            Add_INFO.acceptfd = temp;
            Add_INFO.flag = FAILURE;
            if (send(Add_INFO.acceptfd, &Add_INFO, sizeof(INFO), 0) == -1)
            {
                ERRLOG("login send3");
            }
            printf("failure send successful\n");
            memset(&Add_INFO, 0, sizeof(INFO));
            break;
        }
    }
}