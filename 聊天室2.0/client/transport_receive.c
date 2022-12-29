#include "func.h"


void transport_receive(void *arg)
{
    INFO TEMP =*(INFO *)arg;
    int fd = open(TEMP.filename,O_WRONLY|O_CREAT|O_APPEND,0664);
    int ret = write(fd,TEMP.txt,strlen(TEMP.txt));
    // printf("ret = %d\n",ret);
    // printf("TEMP.flag = %d\n",TEMP.flag);
    if(TEMP.flag == SUCCESS)
    {
        printf("文件传输结束！\n");
    }
    memset(&TEMP,0,sizeof(TEMP));
    close(fd);
}