#include "func.h"
#include <stdio.h>
#include <stdlib.h>


Person_Linklist* LinklistCreate()
{
    Person_Linklist *Linklist_Head = (Person_Linklist*)malloc(sizeof(Person_Linklist)*1);
    Linklist_Head->next = Linklist_Head;
    return Linklist_Head;
}
