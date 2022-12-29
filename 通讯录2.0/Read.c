#include <stdio.h>
#include "func.h"
#include <string.h>
#include <stdlib.h>

int Read(Person_Linklist *Linklist_Head)
{
    FILE *fp = fopen("1.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    while (1)
    {
        Person_Linklist *temp = (Person_Linklist *)malloc(sizeof(Person_Linklist) * 1);
        if (0 == fread(temp, sizeof(Person_Linklist), 1, fp))
        {
            if (feof(fp))
            {
                break;
            }
            else
            {
                perror("fwrite");
                return -1;
            }
        }
        temp->next = Linklist_Head->next;
        Linklist_Head->next = temp;
    }
    fclose(fp);
}