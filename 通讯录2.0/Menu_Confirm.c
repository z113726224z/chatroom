#include "func.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char Menu_confirm()
{
	system("clear");
	char ans = '0';
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("\t\t选择是否正确(y/n)\n\n");
	printf("******************************************************\n");
	printf("******************************************************\n");
	getchar();
	scanf("%c", &ans);
	return ans;
}