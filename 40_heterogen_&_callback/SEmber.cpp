#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "SEmber.h"

PSEmber Ember_beker()
{
    PSEmber ember=(PSEmber) malloc(sizeof(SEmber));
    ember->TypeID=2;
    printf("Adjon meg 1 nevet:");
    scanf("%s",ember->nev);
    printf("Szül. év:");
    scanf("%i",&ember->szul_ev);
    return ember;
}

void Ember_kiir(PSEmber FEmber)
{
    printf("Nev:%s\r\n",FEmber->nev);
    printf("Eves:%i\r\n",Ember_mennyi_idos(FEmber));
}

int Ember_mennyi_idos(PSEmber FEmber)
{
    return 2015-FEmber->szul_ev;
}
