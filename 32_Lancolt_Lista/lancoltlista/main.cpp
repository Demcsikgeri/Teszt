#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct SEmber
{
    char nev[20];
    int szul;
    char nem;
    SEmber *next;
};

void SEmber_Beker(struct SEmber* FEmber)
{
    printf("Aggyá nevet:");
    scanf("%s",FEmber->nev);
    printf("szul:");
    scanf("%i",&FEmber->szul);
    printf("NEm:");
    fflush(stdin);
    scanf("%c",&FEmber->nem);
}

void SEmber_Kiir(struct SEmber* FEmber)
{
    printf("Név:%s",FEmber->nev);
    printf("Szul:%i",FEmber->szul);
    printf("Nem:%c",FEmber->nem);
}

struct SEmber *Head=NULL;
void SEmber_Felfuz(struct SEmber* FEmber)
{
    if (Head==NULL)
    {
        Head=FEmber;
        return;
    }
    struct SEmber* Act=Head;

    while(Act->next!=NULL)
        Act=Act->next;

    Act->next=FEmber;
}

void SEmber_Lista_Kiir()
{
    struct SEmber* Act=Head;

    while(Act!=NULL)
    {
        SEmber_Kiir(Act);
        Act=Act->next;
    }
}

void SEmber_Lista_Torles(int idx)
{
    if (Head==NULL)
        return;

    struct SEmber* Act=Head;

        if (idx==0)
        {
            Head=Act->next;
            free(Act);
        }

    int i;
    for (i=0; i<(idx-1); i+=1)
    {
        Act=Act->next;
        if(Act==NULL)
            return;
    }


    struct SEmber* tmp=Act->next;
    Act->next=Act->next->next;
    free(tmp);
}

int main()
{
    while(1)
    {
        struct SEmber* p=(struct SEmber*)malloc(sizeof(struct SEmber));
        SEmber_Beker(p);
        SEmber_Kiir(p);
        SEmber_Felfuz(p);
    }

    return 0;
}
