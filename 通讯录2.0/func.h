#ifndef FUNC_H_
#define FUNC_H_
#define MAX 1024

typedef struct Head
{
    char id[20];
    char name[32];
    char age[3];
    char sex[10];
    char tel[12];
    struct Head *next;
}Person_Linklist;


void Welcome();
int Menu();
char Menu_confirm();
Person_Linklist* LinklistCreate();
void Add_Personinfo(Person_Linklist *Linklist_Head);
void Printpresent(Person_Linklist *Linlist_Head);
void SortbyName(Person_Linklist *Linklist_Head);
void Display(Person_Linklist *Linklist_Head);
void Printall(Person_Linklist *Linklist_Head);
void DeleteybyID(Person_Linklist *Linklist_Head);
void Search(Person_Linklist *Linklist_Head);
void printfp(Person_Linklist *p);
void Modify(Person_Linklist *Linklist_Head);
int Save(Person_Linklist *Linklist_Head);
int Read(Person_Linklist *Linklist_Head);
#endif

