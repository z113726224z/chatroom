#include <stdio.h>
#include "func.h"

int Save(Person_Linklist *Linklist_Head)
{
    FILE *fp = fopen("./1.txt", "w");
    if (NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    Person_Linklist *temp = Linklist_Head->next;
    while (temp != Linklist_Head)
    {
        if (1 != fwrite(temp, sizeof(Person_Linklist), 1, fp))
        {
            perror("fwrite");
            return -1;
        }
        temp = temp->next;
    }
    fclose(fp);
}