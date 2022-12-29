#include "func.h"


Online* Online_LinklistCreate()
{
    Online *Linklist_Head = (Online*)malloc(sizeof(Online)*1);
    Linklist_Head->next = NULL;
    return Linklist_Head;
}
