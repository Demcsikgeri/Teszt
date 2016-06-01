#include <malloc.h>

#include "SMacska.h"
#include "EnKicsiListam.h"

PSMacska *L=NULL;
int L_elemszam=0;

void Add(PSMacska FMacska)
{
    L=(PSMacska *)realloc(L,sizeof(PSMacska)*(L_elemszam+1));
    L_elemszam+=1;
    L[L_elemszam-1]=FMacska;
}

void Del(int idx)
{
    if (idx>(L_elemszam-1))
        return;

    free(L[idx]);

    for(; idx<L_elemszam-1; idx+=1)
        L[idx]=L[idx+1];

    L=(PSMacska *)realloc(L,sizeof(PSMacska)*(L_elemszam-1));
    L_elemszam-=1;
}

PSMacska Remove(int idx)
{
    if (idx>(L_elemszam-1))
        return NULL;

    PSMacska tmp=L[idx];
    for(; idx<L_elemszam-1; idx+=1)
        L[idx]=L[idx+1];
    L=(PSMacska *)realloc(L,sizeof(PSMacska)*(L_elemszam-1));
    L_elemszam-=1;
    return tmp;
}

void Insert(int idx,PSMacska FMacska)
{
    if (idx>L_elemszam)
        return;

    L=(PSMacska *)realloc(L,sizeof(PSMacska)*(L_elemszam+1));
    L_elemszam+=1;

    int i;

    for (i=L_elemszam-1; i>idx; i-=1)
        L[i]=L[i-1];


    L[idx]=FMacska;
}

void Replace(int idx_a,int idx_b)
{
    if (
        (idx_a>(L_elemszam-1))
        ||
        (idx_b>(L_elemszam-1))
        )
        return;

    PSMacska tmp=L[idx_b];
    L[idx_b]=L[idx_a];
    L[idx_a]=tmp;
}






