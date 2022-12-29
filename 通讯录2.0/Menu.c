#include "func.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int Menu()
{
	int num = 0;
	system("clear");
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("\t\t1.添加信息     2.显示信息\n");
	printf("\t\t3.修改信息     4.删除信息\n");
	printf("\t\t5.查找信息     6.退出系统\n");
	printf("******************************************************\n");
	printf("******************************************************\n");
	scanf("%d", &num);
	return num;
}