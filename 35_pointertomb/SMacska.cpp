#include <stdio.h>
#include <malloc.h>

#include "SMacska.h"

void kiir(PSMacska FMacska)
{
    printf("Név:%s\r\n", FMacska->nev);
    printf("Suly:%i\r\n", FMacska->suly);
    printf("Kor:%i\r\n", FMacska->kor);
}

PSMacska beker()
{
    PSMacska tmp=(PSMacska) malloc(sizeof(SMacska));

    printf("\r\nNév:");
    scanf("%s",tmp->nev);
    printf("\r\nSuly:");
    scanf("%i",&tmp->suly);
    printf("\r\nKor:");
    scanf("%i",&tmp->kor);
    printf("\r\n");

    return tmp;
}
