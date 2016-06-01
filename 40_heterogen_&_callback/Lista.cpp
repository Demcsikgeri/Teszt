#include <malloc.h>
#include "Lista.h"

//int t[100];  // statikus  |  int  | tömb
//int *t;      // dinamikus | "int" | tömb
void**t=NULL; // dinamikus | pointer("void*") | tömb
int t_elemszam=0;

void hozzaad(void* FElem)
{
    // 100 elemû dinamikus int tömb
    // int *z=(int *)malloc(100*sizeof(int));
    // t=(void**)malloc(100*sizeof(void *));
    t=(void**)realloc(t,(t_elemszam+1)*sizeof(void *));
    t_elemszam+=1;
    t[t_elemszam-1]=FElem;
}

void beszur(int FIndex, void *FElem)
{
    if (t_elemszam<=FIndex)
        return;

    t=(void**)realloc(t,(t_elemszam+1)*sizeof(void*));
    t_elemszam+=1;

    int i;

    for (i=t_elemszam-1; i > FIndex; i-=1)
        t[i]=t[i-1];

    t[FIndex]=FElem;
}

void torol(int FIndex)
{
    if (t_elemszam<=FIndex)
        return;

    int i;

    t_elemszam-=1;

    for (i=FIndex; i<t_elemszam; i+=1)
        t[i]=t[i+1];

    t=(void**)realloc(t,t_elemszam*sizeof(void *));
}

void cserel(int FA_Index,int FB_Index)
{
    void *tmp=t[FA_Index];
    t[FA_Index]=t[FB_Index];
    t[FB_Index]=tmp;
}

void bejar(PFenkicsicallbackem Fenkicsicallbackem)
{
    int i;

    for (i=0;i<t_elemszam;i+=1)
        Fenkicsicallbackem(t[i]);
}
