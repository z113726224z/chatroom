#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void printfp(Person_Linklist *p)
{
    system("clear");
    printf("******************************************************\n");
    printf("1.ID号：%s\n", p->id);
    printf("2.姓名：%s\n", p->name);
    printf("3.年龄：%s\n", p->age);
    printf("4.性别：%s\n", p->sex);
    printf("5.电话：%s\n", p->tel);
    printf("******************************************************\n");
    return;
}