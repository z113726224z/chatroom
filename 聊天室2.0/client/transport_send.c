#include "func.h"
extern INFO Add_INFO;

void transport_send(int sockfd)
{
    printf("请输入你要传输的用户\n");
    scanf("%s", Add_INFO.name);
NEXT:
    printf("请输入你要传输的文件\n");
    scanf("%s", Add_INFO.filename);

    Add_INFO.CMD = TRANSPORT;

    int fd = open(Add_INFO.filename, O_RDONLY);
    if (fd == -1)
    {
        printf("文件不存在！请重新输入\n");
        goto NEXT;
    }
    else
    {
        while (1)
        {
            int ret = read(fd, Add_INFO.txt, N);
            printf("ret = %d\n", ret);
            if (ret == 0)
            {
                Add_INFO.flag = SUCCESS;
                strcpy(Add_INFO.txt, "");
                if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
                {
                    ERRLOG("send");
                }
                break;
            }
            // printf("%s\n", Add_INFO.txt);
            // printf("flag = %d\n", Add_INFO.flag);
            if (send(sockfd, &Add_INFO, sizeof(INFO), 0) == -1)
            {
                ERRLOG("send");
            }
            if (ret == 0)
            {
                break;
            }
        }
        printf("文件传输完毕！\n");
        sleep(1);
        close(fd);
        return;
    }
}