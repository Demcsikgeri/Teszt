#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct SData
{
    int valami;
    SData* prev;
    SData* next;
};

SData* Head;

void torol(int idx)
{
    if (Head==NULL)
        return;

    SData* Act=Head;

    int i;
    for(i=0; i<idx; i+=1)
    {
        Act=Act->next;
        if (Act==NULL)
            return;
    }

    if(Act->prev!=NULL)
        Act->prev->next=Act->next;

    if(Act->next!=NULL)
        Act->next->prev=Act->prev;

    free(Act);

    /*
    struct SData* tmp=Act->next;
    Act->next=Act->next->next;
    free(tmp);
    Act=Act->next->next;
    Act->prev=Act->prev->prev;*/


    /*
    struct SData* tmp=Act->next;
    Act->next->next->prev=Act;
    Act->next=Act->next->next;
    free(tmp);*/
}

void beszur(SData* uj, int idx)
{
    if(Head==NULL)
    {
        if (idx==0)
            Head=uj;
        else
            return;
    }

    SData* Act=Head;

    int i;
    for(i=0; i<idx; i+=1)
    {
        Act=Act->next;
        if (Act==NULL)
            return;
    }

    uj->next=Act;
    uj->prev=Act->prev;

    if (Head!=Act)
        Act->prev->next=uj;

    Act->prev=uj;
}

void hozzaad(SData* uj)
{
    uj->next=NULL;

    if (Head==NULL)
    {
        Head=uj;
        uj->prev=NULL;
        return;
    }

    SData* Act=Head;

    while(Act->next)
        Act=Act->next;

    Act->next=uj;
    uj->prev=Act;
}

void kiir()
{
    SData *Act=Head;

    while(Act!=NULL)
    {
        printf("%i\n",Act->valami);
        Act=Act->next;
    }
}

struct SData* beker()
{
    struct SData* tmp=(struct SData*)malloc(sizeof(struct SData));

    printf("Kell szam:");
    scanf("%i",&tmp->valami);
    return tmp;
}

struct SData* eltavolit(int idx)
{
    if (Head==NULL)
        return NULL;

    SData* Act=Head;

    int i;
    for(i=0; i<idx; i+=1)
    {
        Act=Act->next;
        if (Act==NULL)
            return NULL;
    }

    if(Act->prev!=NULL)
        Act->prev->next=Act->next;

    if(Act->next!=NULL)
        Act->next->prev=Act->prev;

    return Act;
}

void csere(int a, int b)
{
    struct SData *tmp_a=eltavolit(a);
    if (tmp_a==NULL)
        return;

    struct SData *tmp_b=eltavolit((a<b)? (b-1):(b));
    if (tmp_b==NULL)
        return;

    if (b>a)
    {
        beszur(tmp_b,a);
        beszur(tmp_a,b);
    }
    else
    {
        beszur(tmp_a,b);
        beszur(tmp_b,a);
    }
}

int main()
{
    hozzaad(beker());
    hozzaad(beker());
    hozzaad(beker());
    beszur(beker(),1);
    kiir();

    getch();
}
