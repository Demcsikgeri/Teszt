#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "STuzolto.h"

PSTuzolto Tuzolto_beker()
{
    PSTuzolto Tuzolto=(PSTuzolto) malloc(sizeof(STuzolto));
    Tuzolto->TypeID=1;
    printf("Adjon meg 1 nevet:");
    scanf("%s",Tuzolto->nev);
    printf("Szül. év:");
    scanf("%i",&Tuzolto->szul_ev);
    printf("Rang:");
    scanf("%i",&Tuzolto->rang);
    return Tuzolto;
}

void Tuzolto_kiir(PSTuzolto FTuzolto)
{
    printf("Nev:%s\r\n",FTuzolto->nev);
    printf("Eves:%i\r\n",Tuzolto_mennyi_idos(FTuzolto));
    printf("Rang:%i\r\n",FTuzolto->rang);
}

int Tuzolto_mennyi_idos(PSTuzolto FTuzolto)
{
    return 2015-FTuzolto->szul_ev;
}
