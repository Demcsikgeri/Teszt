#include <iostream>
#include <conio.h>

#include "SMacska.h"
#include "EnKicsiListam.h"

void Listazas()
{
    int i;
    for (i=0;i<L_elemszam;i+=1)
        kiir(L[i]);
}


int main()
{
    PSMacska tmp=beker();
    kiir(tmp);
    Add(tmp);



    getch();

    return 0;
}
