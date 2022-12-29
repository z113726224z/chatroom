#include "func.h"

int check_id(INFO* Add_INFO)
{
    // printf("check_id start\n");
    // printf("ID = %s\n",Add_INFO->name);
    sqlite3 *ppdb;                              //数据库句柄指针，用来表示操作某一个数据库
    int ret = sqlite3_open("./INFO.db", &ppdb); //打开或者创建一个数据库
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_open: %s\n", sqlite3_errmsg(ppdb));
    }
    char sql[128] = {0};
    sprintf(sql, "select *from stu where id = '%s';",Add_INFO->id);
    char **result;
    int row, column;
    ret = sqlite3_get_table(ppdb, sql, &result, &row, &column, NULL);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_get_table: %s\n", sqlite3_errmsg(ppdb));
    }
    return row;   
}