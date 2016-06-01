#include <stdio.h>
#include <conio.h>

#include "SEmber.h"
#include "STuzolto.h"
#include "Lista.h"

void kiir_elem(void *FElem) // callback függvény
{
    switch (*((int *)FElem))
    {
     case 1: Tuzolto_kiir((PSTuzolto)FElem); break;
     case 2: Ember_kiir((PSEmber)FElem); break;
    }

    //printf("Elemet kaptam:%x\r\n",FElem);
}

int main()
{
    printf("1\r\n");
    bejar(kiir_elem);

    printf("2\r\n");
    hozzaad(Ember_beker());
    bejar(kiir_elem);

    printf("3\r\n");
    beszur(0,Tuzolto_beker());
    bejar(kiir_elem);

    printf("4\r\n");
    hozzaad(Tuzolto_beker());
    bejar(kiir_elem);

    printf("5\r\n");
    cserel(0,2);
    bejar(kiir_elem);

    getch();

    return 0;
}
