#include <stdio.h>
#include "func.h"
#include <stdlib.h>


void Printpresent(Person_Linklist *Linklist_Head)
{
    Person_Linklist *p = Linklist_Head->next;


    //system("clear");
    printf("******************************************************\n");
    printf("ID号：%s\n", p->id);
    printf("姓名：%s\n", p->name);
    printf("年龄：%s\n", p->age);
    printf("性别：%s\n", p->sex);
    printf("电话：%s\n", p->tel);
    printf("******************************************************\n");
}