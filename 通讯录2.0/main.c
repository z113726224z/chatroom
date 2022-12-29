#include <stdio.h>
#include "func.h"
#include <stdlib.h>
int Person_COUNT = 0;

int main(int argc, char const *argv[])
{
    Welcome();
    Person_Linklist *head = LinklistCreate();
    Read(head);
    Person_Linklist *p = head;
    while(p->next != head)
    {
        Person_COUNT++;
        p = p->next;
    }
    while (1)
    {
        int num = 0;
        char ans = '0';
        int flag = 1;
        while (flag)
        {
            num = Menu();
            ans = Menu_confirm();
            if (ans == 'y')
            {
                break;
                flag = 0;
            }
            else if (ans == 'n')
            {
                continue;
            }
            else if (ans != 'y' && ans != 'n')
            {
                printf("请正确输入！\n");
                while ('\n' != getchar())
                    ;
                continue;
            }
        }

        switch (num)
        {
        case 1:
            Add_Personinfo(head);
            break;
        case 2:
            Display(head);
            printf("请按q键退出！\n");
            while (1)
            {
                char re = '0';
                scanf(" %c", &re);
                if (re == 'q')
                {
                    break;
                }
            }
            break;
        case 3:
            Modify(head);
            break;
        case 4:
            DeleteybyID(head);
            break;
        case 5:
            Search(head);
            break;
        case 6:
            system("clear");
            Save(head);
            Person_Linklist *p = head;
            while (p->next != head)
            {
                Person_Linklist *temp = p;
                p = p->next;
                free(temp);
            }
            exit(0);
            
        }  
    }

    return 0;
}
